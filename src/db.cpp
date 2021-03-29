/** 
 *  @file   db.cpp 
 *  @brief  DataBase Class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "db.h"

/** 
 * @brief Result Data Base contructor
*/
ResultDB::ResultDB(){
    quantity_out = 0; 
    quantity_in = 0;
    sumPercentage_out = 0;
    sumPercentage_in = 0;

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
        return quantity_in;
    }
    else{
        return quantity_out;
    }
}

/** 
 * @brief Return the percentage of the day
 * @param inFLag True for incoming plates, False to outgoing
 * @return Percentage
*/
unsigned int ResultDB::dayPercentage(bool inFLag){
    if(inFLag){
        if (quantity_in > 0)
            return (unsigned int)(sumPercentage_in/quantity_in);
    }
    else{
        if (quantity_out > 0)
            return (unsigned int)(sumPercentage_out/quantity_out);
    }
    return 0;
}

/** 
 * @brief Add one plate to the day counter
 * @param inFLag True for incoming plates, False to outgoing
*/
void ResultDB::addOnePlate(bool inFLag){
    if(inFLag){
        quantity_in++;
    }
    else{
        quantity_out++;
    }
}

/** 
 * @brief Add one percentage to the day
 * @param inFLag True for incoming plates, False to outgoing
*/
void ResultDB::addOnePercentage(bool inFLag, unsigned int percentage){
    if(inFLag){
        sumPercentage_in += percentage;
    }
    else{
        sumPercentage_out += percentage;
    }
}

/** 
 * @brief Request the quantity of a period of time (Incoming and outgoing)
 * @param startDate Start date to filter the DB
 * @param endDate End date to filter the DB
 * @param in Reference variable to return the incoming quantity
 * @param out Reference variable to return the outgoing quantity
*/
int ResultDB::requestQuantity(std::string startDate, std::string endDate, unsigned int &in, unsigned int &out){
    //TODO//
    return 1;
}

/** 
 * @brief Request the percentage of a period of time (Incoming and outgoing)
 * @param startDate Start date to filter the DB
 * @param endDate End date to filter the DB
 * @param in Reference variable to return the incoming percentage
 * @param out Reference variable to return the outgoing percentage
*/
int ResultDB::requestPercentage(std::string startDate, std::string endDate, unsigned int &in, unsigned int &out){
    //TODO//
    return 1;
}

/** 
 * @brief Request the quantity and the percentage of a period of time
 * @param startDate Start date to filter the DB
 * @param endDate End date to filter the DB
*/
int ResultDB::csvFile(std::string startDate, std::string endDate){
    //TODO//
    return 1;
}

void ResultDB::processRecords(std::future<void> futureObj){
    
    while ((futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) )
    {
        DBNewRecord dataToDB = newDataResult.Process();

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
