/** 
 *  @file   db.h 
 *  @brief  DataBase Class header file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#ifndef DB_H
#define DB_H


#include <stdio.h>
#include <iostream>
#include <mutex>
#include <vector>
#include "plate.h"
#include <ctime>


/** 
 * @brief PlateDB base class than contains the Attributes witch will be include in the DB
*/
class PlateDB {
    public:
        PlateDB(std::string uPlateName, std::string uDate, bool uInFlag, unsigned int uPercentage, 
                 unsigned int uExpPercentage, bool uManualSource) : plateName(uPlateName), date(uDate), 
                 inFLag(uInFlag), percentage(uPercentage), expPercentage(uExpPercentage), 
                 manualSource(uManualSource) {};

        /* Get functions */
        std::string PlateName(void) {return plateName;};
        std::string Date(void) {return date;};
        bool IncomingDirection(void) {return inFLag;};
        unsigned int Percentage(void) {return percentage;};
        unsigned int ExpPercentage(void) {return expPercentage;};
        bool ManualSource(void) {return manualSource;};
        /* Set functions */
        void PlateName(std::string uPlateName){plateName = uPlateName;};
        void Date(std::string uDate){date = uDate;};
        void IncomingDirection(bool uInFlag){inFLag = uInFlag;};
        void Percentage(unsigned int uPercentage){percentage = uPercentage;};
        void ExpPercentage(unsigned int uExpPercentage){expPercentage = uExpPercentage;};
        void ManualSource(bool uManualSource){manualSource = uManualSource;};

    private:    
        friend class ResultDB; /* Give access to private members */

        std::string plateName;
        std::string date;
        bool inFLag;
        unsigned int percentage;
        unsigned int expPercentage;
        bool manualSource;
};


template <class T>
class DataBase
{
public:
    DataBase(std::string uDbName) : dbName(uDbName) {};
    std::string DbName(void) {return dbName;};
    void DbName(std::string uDbName) {dbName = uDbName;};

    unsigned int AskId(std::string date);
    std::vector<T>request(unsigned int startId, unsigned int endId);
    void send(T &&data);
private:
    std::mutex _mutex_data;
    std::string dbName;
};


class ResultDB {
    public:
        unsigned int dayQuantity(bool inFLag);
        unsigned int dayPercentage(bool inFLag);
        void addOnePlate(bool inFLag);
        void addOnePercentage(bool inFLag, unsigned int percentage);

        int requestQuantity(std::string startDate, std::string endDate, unsigned int &in, unsigned int &out);
        int requestPercentage(std::string startDate, std::string endDate, unsigned int &in, unsigned int &out);
        int csvFile(std::string startDate, std::string endDate);
    private:
        PlateDB _data;
        DataBase<PlateDB> newDataResult;
        DataBase<Plate> newDataPlate;
        unsigned int quantity_out;  ///< Store the partial day result to avoid ask all the time to the DB - Number of plates outgoing
        unsigned int sumPercentage_out; ///< Percentage summation of the day
        unsigned int quantity_in;  ///< Store the partial day result to avoid ask all the time to the DB - Number of plates outgoing
        unsigned int sumPercentage_in; ///< Percentage summation of the day
};


#endif