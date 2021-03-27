/** 
 *  @file   records.cpp
 *  @brief  Records class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/        

#include "records.h"

/** 
 * @brief Perform the accion of enter manual data to the data base. This manual action is mainly for debug
 *        because give to the user power to add new entry but don't give a way to remove or check the list.
*/
void Record::EnterManualData(){
    //TODO//
}

/** 
 * @brief Perform the call to the DB function to store the information into a csv file.
*/
void Record::RunExportCsv(void){
    //TODO//
}

/** 
 * @brief Refresh the GUI with the most recent data. If the Find status is set, the screen will request 
 *        new data from the DB to update the fields with the information between the start and end date
 * @param None
*/
void Record::refreshScreen(int uFindStatus){
    //TODO//
}        

/** 
 * @brief Check the format and the data of the date.
 * @param uDate Date to be validated
 * @return True if it is validated
*/
bool Record::ValEditDate(std::string uDate){
    //TODO//
    return true;
}

/** 
 * @brief Check the format and the data of the quantity.
 * @param uQuantity Quantity to be validated
 * @return True if it is validated
*/
bool Record::ValEditQuantity(std::string uQuantity){
    //TODO//
    return true;
}

/** 
 * @brief Check the format and the data of the Percentage.
 * @param uPercentage Percentage to be validated
 * @return True if it is validated
*/
bool Record::ValEditPercentage(std::string uPercentage){
    //TODO//
    return true;
}

/* PRIVATE FUNCTIONS */

/** 
 * @brief Internal function to request to the DB the quantity
 * @param uInflag True if it is incoming and false for outgoing
 * @return String of the quantity to be printed in the screen
*/
std::string Record::PrintQuantity(bool uInflag){
    //TODO//
    return "";
}

/** 
 * @brief Internal function to request to the DB the percentage
 * @param uInflag True if it is incoming and false for outgoing
 * @return String of the percentage to be printed in the screen
*/
std::string Record::PrintPercentage(bool uInflag){
    //TODO//
    return "";
}  

/** 
 * @brief Internal function to request to the DB the quantity base of the start and end date
 * @param uInflag True if it is incoming and false for outgoing
 * @return String of the quantity base of the start and end date to be printed in the screen
*/
void Record::PrintFindQuantity(void){
    //TODO//
}

/** 
 * @brief Internal function to request to the DB the percentage base of the start and end date
 * @param uInflag True if it is incoming and false for outgoing
 * @return String of the percentage base of the start and end date to be printed in the screen
*/
void Record::PrintFindPercentage(void){
    //TODO//
}

void Record::dPrintObj() {
    if (Record::LogFlag())
    {
        std::ofstream debugFile;
        debugFile.open (Path() + Filename(), std::ios::app); /* All output operations are performed at the end of the file, Append */
        if (debugFile.is_open()) {
            debugFile << "OBJ RECORD - isRunning: " << Record::isRunning << std::endl;
            debugFile.close();
        }
        else
        {
            std::cout << "ERROR: Cannot open the log file" << std::endl;
        }
    }
};

