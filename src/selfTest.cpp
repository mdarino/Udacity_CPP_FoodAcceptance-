/** 
 *  @file   selfTest.cpp
 *  @brief  Self test source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "debugFood.h"
#include "selfTest.h"

/* Self test implementation */
bool selfTest(void){
    bool result = false;
    result = selfTest_debug();
    return result;
}

/* Debug class self test implementation */
bool selfTest_debug(void){
     class AbstractForTest : public DebugFood {   /* Create and temp class because the debugFood class is an astract class */
        public:
            AbstractForTest(std::string uFile, std::string uPath, bool logStatus):DebugFood(uFile, uPath, logStatus)  {};
            void dPrintObj() {
                std::ofstream debugFile;
                debugFile.open (Path() + Filename(), std::ios::app); /* All output operations are performed at the end of the file, Append */
                if (debugFile.is_open()) {
                    debugFile << "TEST:" << testData << std::endl;
                    debugFile.close();
                }
                else
                {
                    std::cout << "ERROR: Cannot open the log file" << std::endl;
                }
            };
            std::string testData = "SelfTestData";
    };

    AbstractForTest myDebug("test.txt","../log/",true);
    remove((myDebug.Path() + myDebug.Filename()).c_str()); /* Test with an empty file*/
    myDebug.dPrint("SELFTEST");
    myDebug.dPrint("DEBUGFOOD","TEST");
    myDebug.dPrintObj();

    /* Check results */

    std::string line;
    std::ifstream stream(myDebug.Path() + myDebug.Filename());
    bool result = true;
    if (stream.is_open()) {
        std::getline(stream, line);
        if("SELFTEST" != line) result = false;
        std::getline(stream, line);
        if("N:DEBUGFOOD-TEST" != line) result = false;
        std::getline(stream, line);
        if("TEST:SelfTestData" != line) result = false;
    }
    else {result = false;}

    return result;
}

