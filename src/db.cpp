/** 
 *  @file   db.cpp 
 *  @brief  DataBase Class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "db.h"

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
        return (unsigned int)(sumPercentage_in/quantity_in);
    }
    else{
        return (unsigned int)(sumPercentage_out/quantity_out);
    }
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
      
      
      std::this_thread::sleep_for(std::chrono::seconds(3));
      std::cout << "My DB";

    }
}
