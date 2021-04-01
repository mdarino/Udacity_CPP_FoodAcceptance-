/** 
 *  @file   db.cpp 
 *  @brief  DataBase Class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "db.h"


static unsigned int findQuaOut;  ///< Store the partial day result to avoid ask all the time to the DB - Number of plates outgoing
static unsigned int findSumPerOut; ///< Percentage summation of the day
static unsigned int findQuaIn;  ///< Store the partial day result to avoid ask all the time to the DB - Number of plates outgoing
static unsigned int findSumPerIn; ///< Percentage summation of the day
static std::ofstream csvFileFd;

int callbackUpdate(void *data, int argc, char **argv, char **azColName);
int callbackCsv(void *data, int argc, char **argv, char **azColName);


/** 
 * @brief Result Data Base contructor
*/
ResultDB::ResultDB(std::string uFile, std::string uPath, bool logStatus): DebugFood(uFile, uPath, logStatus) {
    
    quantityOut = 0; 
    quantityIn = 0;
    sumPercentageOut = 0;
    sumPercentageIn = 0;

    char *zErrMsg = 0;
    int rc;
 
    /* Open database / Or create it */
    rc = sqlite3_open("../data/myDB.db", &db);
    if( rc ) {
       std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    } else {
       std::cout << "Open database: " << std::endl;
    }

    /* Create SQL statement */
    const char* sql = "CREATE TABLE PLATES(" \
      "ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
      "NAME TEXT NOT NULL," \
      "DATE TEXT NOT NULL," \
      "INFLAG INT NOT NULL," \
      "PERCENTAGE INT NOT NULL," \
      "EXPECTED INT NOT NULL," \
      "MANUAL INT NOT NULL );";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        std::cout << "SQL: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

}

/** 
 * @brief Result Data Base destructor
*/
ResultDB::~ResultDB(){
    sqlite3_close(db);
}

/** 
 * @brief Return the quantity of plates of current day
 * @param inFLag True for incoming plates, False to outgoing
 * @return Quantity of plates
*/
unsigned int ResultDB::dayQuantity(bool inFLag){
    if(inFLag){
        return quantityIn;
    }
    else{
        return quantityOut;
    }
}

/** 
 * @brief Return the percentage of the day
 * @param inFLag True for incoming plates, False to outgoing
 * @return Percentage
*/
unsigned int ResultDB::dayPercentage(bool inFLag){
    if(inFLag){
        if (quantityIn > 0)
            return (unsigned int)(sumPercentageIn/quantityIn);
    }
    else{
        if (quantityOut > 0)
            return (unsigned int)(sumPercentageOut/quantityOut);
    }
    return 0;
}

/** 
 * @brief Add one plate to the day counter
 * @param inFLag True for incoming plates, False to outgoing
*/
void ResultDB::addOnePlate(bool inFLag){
    if(inFLag){
        quantityIn++;
    }
    else{
        quantityOut++;
    }
}

/** 
 * @brief Add one percentage to the day
 * @param inFLag True for incoming plates, False to outgoing
*/
void ResultDB::addOnePercentage(bool inFLag, unsigned int percentage){
    if(inFLag){
        sumPercentageIn += percentage;
    }
    else{
        sumPercentageOut += percentage;
    }
}

/** 
 * @brief Request the quantity and the percentage of a period of time
 * @param startDate Start date to filter the DB
 * @param endDate End date to filter the DB
*/
void ResultDB::requestUpdate(std::string startDate, std::string endDate){
    findQuaOut = 0;
    findSumPerOut = 0;
    findQuaIn = 0;
    findSumPerIn = 0;
    std::cout << "FIND: " << startDate << " to " << endDate << " (Not inclusive)" << std::endl;
    ResultDB::readDB(DB_READ_TYPE::FIND, startDate, endDate);
}

/** 
 * @brief Request the quantity and the percentage of a period of time
 * @param startDate Start date to filter the DB
 * @param endDate End date to filter the DB
*/
void ResultDB::csvFile(std::string startDate, std::string endDate){
    std::cout << "CSV: " << startDate << " to " << endDate << " (Not inclusive)" << std::endl;
    
    csvFileFd.open (DB_CSV_FILE);
    if (csvFileFd.is_open()) {
        ResultDB::readDB(DB_READ_TYPE::CSV, startDate, endDate);
        csvFileFd.close();
    }
}

/** 
 * @brief Return the quantity of plates for the find request
 * @param inFLag True for incoming plates, False to outgoing
 * @return Quantity of plates
*/
unsigned int ResultDB::findQuantity(bool inFLag){
    if(inFLag){
        return findQuaIn;
    }
    else{
        return findQuaOut;
    }
}

/** 
 * @brief Return the percentage for the find request
 * @param inFLag True for incoming plates, False to outgoing
 * @return Percentage
*/
unsigned int ResultDB::findPercentage(bool inFLag){
    if(inFLag){
        if (findQuaIn > 0)
            return (unsigned int)(findSumPerIn/findQuaIn);
    }
    else{
        if (findQuaOut > 0)
            return (unsigned int)(findSumPerOut/findQuaOut);
    }
    return 0;
}

void ResultDB::processRecords(std::future<void> futureObj){
    
    while ((futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) )
    {
        DBNewRecord dataToDB = newDataResult.Process();

        if((dataToDB.plateName == "") && (dataToDB.date == "") && (dataToDB.percentage == 0))/* Check special message to close */
        {
            std::cout << "Exit DB - Special Message" << std::endl;
            break; 
        }

        char *zErrMsg = 0;
        int rc;
        /* Create SQL statement */
        std::string sqlCmd = "INSERT INTO PLATES (NAME,DATE,INFLAG,PERCENTAGE,EXPECTED,MANUAL) VALUES ('" + 
                            dataToDB.plateName + "', '" + dataToDB.date + "', " + 
                             std::to_string((int)dataToDB.inFLag) + ", " +
                             std::to_string(dataToDB.percentage)+ ", " +
                             std::to_string(dataToDB.expPercentage)+ ", " +
                             std::to_string((int)dataToDB.manualSource)+ ");";
        /* Execute SQL statement */
        const char* sql = sqlCmd.c_str();
        rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
        if( rc != SQLITE_OK ) {
            std::cout << "SQL: " << zErrMsg << std::endl;
            sqlite3_free(zErrMsg);
        } else {
            std::cout << "Process DB" << std::endl;
        }
    }
    std::cout << " END PROCESS RECORDS" << std::endl;
}


void ResultDB::dPrintObj() {
    if (ResultDB::LogFlag())
    {
        std::ofstream debugFile;
        debugFile.open (Path() + Filename(), std::ios::app); /* All output operations are performed at the end of the file, Append */
        if (debugFile.is_open()) {
            debugFile << "OBJ DB - quantity_out: " << ResultDB::quantityOut << std::endl;
            debugFile << "OBJ DB - sumPercentage_out: " << ResultDB::sumPercentageOut << std::endl;
            debugFile << "OBJ DB - quantity_in: " << ResultDB::quantityIn << std::endl;
            debugFile << "OBJ DB - sumPercentage_in: " << ResultDB::sumPercentageIn << std::endl;
            debugFile.close();
        }
        else
        {
            std::cout << "ERROR: Cannot open the log file" << std::endl;
        }
    }
};


void ResultDB::readDB(DB_READ_TYPE type, std::string startDate, std::string endDate){
    char *zErrMsg = 0;
    int rc;
     /* Create SQL statement */
    std::string sqlCmd = "SELECT * from PLATES Where DATE BETWEEN date('" + 
                        startDate + "') AND date('" + endDate + "')";    
    const char* data = ""; 
    /* Execute SQL statement */
    if(type == DB_READ_TYPE::FIND)
        rc = sqlite3_exec(db, sqlCmd.c_str(), callbackUpdate, (void*)data, &zErrMsg);
    if(type == DB_READ_TYPE::CSV) 
       rc = sqlite3_exec(db, sqlCmd.c_str(), callbackCsv, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        std::cout << "SQL: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "DB - READ OK" << std::endl;
    }
}


int callbackUpdate(void *data, int argc, char **argv, char **azColName){
    int percentage = std::stoi(argv[DB_RECORD::PERCENTAGE]);
    if (std::string(argv[DB_RECORD::INFLAG]) == "1")
    {
        findQuaIn++;
        findSumPerIn += percentage;
        std::cout << "POR" << findSumPerIn << std::endl;
    }
    else
    {
        findQuaOut ++;
        findSumPerOut += percentage;
    }
    return 0;
}


int callbackCsv(void *data, int argc, char **argv, char **azColName){

    csvFileFd << argv[DB_RECORD::ID] << ",";
    csvFileFd << argv[DB_RECORD::NAME] << ",";
    csvFileFd << argv[DB_RECORD::DATE] << ",";
    csvFileFd << argv[DB_RECORD::INFLAG] << ",";
    csvFileFd << argv[DB_RECORD::PERCENTAGE] << ",";
    csvFileFd << argv[DB_RECORD::EXPECTED] << ",";
    csvFileFd << argv[DB_RECORD::MANUAL];
    csvFileFd << std::endl;
    return 0;
}


