/** 
 *  @file   debugFood.cpp 
 *  @brief  Debug Class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "debugFood.h"

/** 
 * @brief DebugFood constructor
 * @param uFile File name to storage the logs
 * @param uPath Where will be storage the file, folder name and path
 * @param logStatus True Copy the message to file, False print the message in console.
*/
DebugFood::DebugFood(std::string uFile, std::string uPath, bool uLogFlag){
    filename = uFile;
    path = uPath;
    logFlag = uLogFlag;
}

/** 
 * @brief Basic print - Print without Name or format
 * @param text Text to be printed.
*/
void DebugFood::dPrint(std::string text){
    if (logFlag)
    {
        std::ofstream debugFile;
        debugFile.open (path + filename, std::ios::app); /* All output operations are performed at the end of the file, Append */
        if (debugFile.is_open()) {
            debugFile << text << std::endl;
            debugFile.close();
        }
        else
        {
            std::cout << "ERROR: Cannot open the log file" << std::endl;
        }
    }
    else 
    {
        std::cout << "LOG:" << text << std::endl;
    }

}

/** 
 * @brief Print with Name - Print with a name to specify x part of the code
 * @param name Name of the module who is doing the debug log.
 * @param text Text to be printed.
*/
void DebugFood::dPrint(std::string name, std::string text){
    if (logFlag)
    {
        std::ofstream debugFile;
        debugFile.open (path + filename, std::ios::app); /* All output operations are performed at the end of the file, Append */
        if (debugFile.is_open()) {
            debugFile << "N:" << name << "-" << text << std::endl;
            debugFile.close();
        }
        else
        {
            std::cout << "ERROR: Cannot open the log file" << std::endl;
        }
    }
    else 
    {
        std::cout << "LOG:" << "N:" << name << "-" << text << std::endl;
    }
}
