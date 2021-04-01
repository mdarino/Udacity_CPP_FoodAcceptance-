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
#include <ctime>
#include <deque>
#include <condition_variable>
#include <future>
#include <thread>
#include <sqlite3.h>
#include "plate.h"
#include "debugFood.h"


#define DB_DATE_FORMAT "%Y-%m-%d %H:%M:%S.000"
#define DB_CSV_FILE "../data/myRecords.csv"

enum DB_RECORD { ID = 0, NAME, DATE, INFLAG, PERCENTAGE, EXPECTED, MANUAL };
enum DB_READ_TYPE { FIND = 0, CSV};


template <class T>
class RecordQueue
{
public:
    RecordQueue(){};
    ~RecordQueue(){};
    T Process()
    {
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_records.empty(); }); // pass unique lock to condition variable
        T msg = std::move(_records.back());
        _records.pop_back();
        return msg;
    }
    void Store(T &&record)
    {
        std::lock_guard<std::mutex> uLock(_mutex);
        _records.push_back(std::move(record));
        _cond.notify_one();
        std::cout << "Store DB" << std::endl;
    }
    
private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<T> _records;
};


/** 
 * @brief PlateDB base class than contains the Attributes witch will be include in the DB
*/
class DBNewRecord {
    public:
        DBNewRecord(std::string uPlateName, std::string uDate, bool uInFlag, unsigned int uPercentage, 
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


class ResultDB : public Plate,  public DebugFood {
    public:
        ResultDB(std::string uFile, std::string uPath, bool logStatus);/* In future Version must take the plate info from the DB */
        ~ResultDB();
        void dPrintObj(); /* Virtual function of the debug class */
        RecordQueue<DBNewRecord> newDataResult;
        unsigned int dayQuantity(bool inFLag);
        unsigned int dayPercentage(bool inFLag);
        void addOnePlate(bool inFLag);
        void addOnePercentage(bool inFLag, unsigned int percentage);

        void requestUpdate(std::string startDate, std::string endDate);
        void csvFile(std::string startDate, std::string endDate);
        unsigned int findQuantity(bool inFLag);
        unsigned int findPercentage(bool inFLag);
        void processRecords(std::future<void> futureObj);

    private:
        unsigned int quantityOut;  ///< Store the partial day result to avoid ask all the time to the DB - Number of plates outgoing
        unsigned int sumPercentageOut; ///< Percentage summation of the day
        unsigned int quantityIn;  ///< Store the partial day result to avoid ask all the time to the DB - Number of plates outgoing
        unsigned int sumPercentageIn; ///< Percentage summation of the day

        sqlite3 *db;
        void readDB(DB_READ_TYPE type, std::string startDate, std::string endDate);

};

#endif