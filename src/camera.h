/** 
 *  @file   camera.h
 *  @brief  Camera class header file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#ifndef CAMERA_H
#define CAMERA_H

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <future>
#include <thread>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


#include "debugFood.h"



/** 
 * @brief Camera Class contains information to process the image
*/
class Camera : public DebugFood {
    public:
        Camera(std::string uFile, std::string uPath, bool logStatus, unsigned int u_Id, bool uSaveFlag) : 
                            DebugFood(uFile, uPath, logStatus), id(u_Id), saveFlag(uSaveFlag)  {};
        void dPrintObj(); /* Virtual function of the debug class */

        unsigned int Id(void) const { return id;};
        bool SaveFlag(void) const { return id;};   
        void Id(unsigned int uId){ id = uId;};
        void SaveFlag(bool uSaveFlag){ saveFlag = uSaveFlag;};

        void processImage(std::future<void> futureObj);

    private:
        unsigned int id; /* Id of the camera/web-cam */
        bool saveFlag; /* True if save images */
        //bool runFlag; /* True -> RUN */

        // Filter for the white plate color
        int const hmin = 0;
        int const smin = 0;
        int const vmin = 145;  
        int const hmax = 179;
        int const smax = 45;
        int const vmax = 255;  

        void getContours(cv::Mat imgGray, cv::Mat img); 

};

#endif
