/** 
 *  @file   selfTest.h 
 *  @brief  Self test header file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#ifndef SELFTEST_H
#define SELFTEST_H

#include <iostream>

/** 
 *  @brief SelfTest of the system. Run all individual self test and return true if all the test passed.
 *  It is performed in the start of the system, some of this test (in future versions) must pass to unit test to get 
 *  faster startup of the program.
 *  To reduce the complexity, the software will check all the test on program startup, but some of this test if works one 
 *  time will work forever for this compilation output. 
*/
bool selfTest(void);

/** 
 *  @brief Self test for the debug class - This test will create a file, 
 *   put some logs and read the file to validate if the data is there.
*/
bool selfTest_debug(void);

/** 
 *  @brief Self test for the plate class
*/
bool selfTest_plate(void);

#endif