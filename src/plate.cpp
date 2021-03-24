/** 
 *  @file   plate.cpp
 *  @brief  Plate class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "plate.h"

/** 
 * @brief Plate constructor
 * @param uPlateName Name of the meal
 * @param uExpPercentage Number between 0 to 100 % 
 * @param uNutrients_A Number of milligrams.
*/
Plate::Plate(std::string uPlateName, unsigned int uExpPercentage, unsigned int uNutrients_A){
    plateName = uPlateName;
    expPercentage = valPercentage(uExpPercentage);
    nutrients_A = valNutrients(uNutrients_A);
}

/** 
 * @brief Set Plate name
 * @param uPlateName Name of the meal
*/
void Plate::PlateName(std::string uPlateName){
        plateName = uPlateName;
}

/** 
 * @brief Set the expected percentage 
 * @param uExpPercentage Number between 0 to 100 % 
*/
void Plate::ExpPercentage(unsigned int uExpPercentage){
    expPercentage = valPercentage(uExpPercentage);
}

/** 
 * @brief Set the Nutrients (Vitamim A)
 * @param uNutrients_A Number of milligrams.
*/
void Plate::Nutrients_A(unsigned int uNutrients_A){
    nutrients_A = valNutrients(uNutrients_A);
}

/* VALIDATE DATA */

/** 
 * @brief Percentage goes between 0 to maxPercentage (If it is out truncate the input)
 * @param uNutrients_A Number of milligrams.
*/
unsigned int Plate::valPercentage (unsigned int uPercentage){
    if (uPercentage > maxPercentage)
      uPercentage = maxPercentage;
    return uPercentage;
} 

/** 
 * @brief Nutrients goes between 0 to maxNutrients (If it is out truncate the input)
 * @param uNutrients_A Number of milligrams.
*/
unsigned int Plate::valNutrients (unsigned int uNutrients){
    if (uNutrients > maxNutrients)
      uNutrients = maxNutrients;
    return uNutrients;
} 