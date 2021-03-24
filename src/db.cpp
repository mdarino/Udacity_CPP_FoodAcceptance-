/** 
 *  @file   db.cpp 
 *  @brief  DataBase Class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "db.h"

/** 
 * @brief Ask for data from the DB
 * @param T Template variable
*/
template <typename T>
std::vector<T> DataBase<T>::request(unsigned int startId, unsigned int endId){
    // Ask for information under the lock
    //TODO//
}

/** 
 * @brief Send new data to the DB
 * @param T Template variable
*/
template <typename T>
void DataBase<T>::send(T &&msg)
{
    // Add information to the DB under the lock
    //TODO//

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
 * @brief Request the quantity and the percentage of a period of time
 * @param startDate Start date to filter the DB
 * @param endDate End date to filter the DB
 * @param inFLag True for incoming plates, False to outgoing
 * @param quantity Reference variable to return the quantity
 * @param percentage Reference variable to return the percentage
*/
int ResultDB::request(std::string startDate, std::string endDate, bool inFLag, unsigned int &quantity, unsigned int &percentage){
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

