/** 
 *  @file   debug.h 
 *  @brief  Debug Class header file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#ifndef DEBUGFOOD_H
#define DEBUGFOOD_H

#include <stdio.h>
#include <iostream>
#include <fstream>


/** 
 * @brief DebugFood Class contains the Attributes and methods to make debugging of the application
*/
class DebugFood {
    public:
        /* Contructor */
        DebugFood(std::string uFile, std::string uPath, bool uLogFlag);
        /* Get/Set */    
        std::string Filename() {return filename;};
        std::string Path() {return path;};
        bool LogFlag() {return logFlag;};
        void Filename(std::string uFile) { filename = uFile;};
        void Path(std::string uPath) { path = uPath;};
        void LogFlag(bool uLogFlag) { logFlag = uLogFlag;};
        /* Methods */
        void dPrint(std::string text); // Generic print in the debug file
        void dPrint(std::string name, std::string text); // Add a name in the line to identify the module
        virtual void dPrintObj() = 0; // Will be defined for the derivated object (for example print the current obj data)
    private:
        std::string filename; // Log file name (static because it is global to all the classes instances)
        std::string path; // File path, folder.
        bool logFlag; // If this flag is true, the log is enabled 
};

#endif