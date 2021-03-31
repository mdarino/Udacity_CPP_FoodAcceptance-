/** 
 *  @file   plate.h
 *  @brief  Plate class header file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#ifndef PLATE_H
#define PLATE_H

#include <stdio.h>
#include "iostream"


constexpr unsigned int maxPercentage = 100; ///< Maximum number accepted on the percentage variables
constexpr unsigned int maxNutrients = 1000; ///< Maximum number accepted on Nutrients variables

/** 
 * @brief Plate Class contains information of the meals, expected values, name, etc
*/
class Plate {
    public:
        /* Constructor */
        Plate() {};
        Plate(std::string uPlateName, unsigned int uExpPercentage, unsigned int uNutrients_A);
        /* Get/Set */  
        std::string PlateName(void) { return plateName;};
        unsigned int ExpPercentage(void) {return expPercentage;};
        unsigned int Nutrients_A(void) {return nutrients_A;};
        void PlateName(std::string uPlateName);
        void ExpPercentage(unsigned int uExpPercentage);
        void Nutrients_A(unsigned int uNutrients_A);
        /* Request to the DB the plate name for the current day */
        void RequestPlateName(void);
        
        /* Function to validate the input values*/
        unsigned int valPercentage (unsigned int uPercentage); 
        unsigned int valNutrients (unsigned int uNutrients); 
    private:
        std::string plateName; /* Meals name */
        unsigned int expPercentage; /* Expected result for this plate, 0 to 100 % */
        unsigned int nutrients_A; /* Quantity of vitamim A - unit on milligrams */  /* ...nutrients_A is an example, add more nutrients in this part.. */

};

#endif