/** 
 *  @file   records.h
 *  @brief  Records class header file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/


#ifndef RECORDS_H
#define RECORDS_H

#include <stdio.h>
#include <iostream>
#include "debugFood.h"

/** Status of the find operation, if the user:
     Empty start and end date = empty 
     Valid Start date and undefined end = validStart 
     Undefined start and Valid end = validEnd
     Both Validated = validate (ready to findRequest)
     Press button Find and Both validated = findRequest (Update to process)
       -> After process the findRequest go to empty and clean the edit box.
      */
enum findStatus_t { empty, validStart, validEnd, validated, findRequest};


/** 
 * @brief Record class contains the main screen information and most of the routines to be call by the GUI
*/
class Record : public DebugFood {
    public:

        Record(std::string uFile, std::string uPath, bool logStatus) : 
                            DebugFood(uFile, uPath, logStatus) {};
        
        void EnterManualData();
        void RunExportCsv(void);
        void refreshScreen(int uFindStatus);        

        bool ValEditDate(std::string uDate);
        bool ValEditQuantity(std::string uQuantity);
        bool ValEditPercentage(std::string uPercentage);

    private:
        std::string PrintQuantity(bool uInflag);
        std::string PrintPercentage(bool uInflag);    
        void PrintFindQuantity(void);
        void PrintFindPercentage(void);

        bool inFLag;
        unsigned int userManualQuantity;
        unsigned int userManualPercentage;
        std::string userDateStart;
        std::string userDateEnd;
        findStatus_t findStatus;      
};


#endif