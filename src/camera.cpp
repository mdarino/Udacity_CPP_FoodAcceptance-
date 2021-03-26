/** 
 *  @file   camera.cpp
 *  @brief  Camera class source file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "camera.h"

/** 
 * @brief Run one image processing
 * @param None
 * @return None
*/

using namespace cv;
RNG rng(12345);

void Camera::processImage(void){

    int randomNumber;
    randomNumber = (std::rand() % 7) + 1;  /* To get random images */

    std::string filename = "../test/img/t" + std::to_string(randomNumber) + ".png";
    Mat img = imread(filename);   /* Mat it is the matrix for the image */
    Mat imgHR, mask, imgGray, imgCircle;
    cvtColor(img, imgHR, COLOR_BGR2HSV); /* Tranform the image to cvtColor */
    Scalar lower(Camera::hmin, Camera::smin, Camera::vmin);
    Scalar upper(Camera::hmax, Camera::smax, Camera::vmax);
    inRange(imgHR, lower, upper, mask); /* Set a range: img, startColor, endColor, mask */
    mask.copyTo(imgCircle);
    getContours(mask,imgCircle);

    imshow("Image", img);
    imshow("mask", mask);
    imshow("cir", imgCircle);
    //int TotalNumberOfPixels = img.rows * img.cols;
    int TotalNumberCirc = countNonZero(imgCircle);
    int WhitePixels = countNonZero(mask);
    std::cout << "White: " << WhitePixels << std::endl;
    std::cout << "Total: " << TotalNumberCirc << std::endl;
    std::cout << "Image:" << randomNumber << " Percentage:" << (int)((WhitePixels*100)/TotalNumberCirc) << std::endl;

}

void Camera::dPrintObj() {
    if (Camera::LogFlag())
    {
        std::ofstream debugFile;
        debugFile.open (Path() + Filename(), std::ios::app); /* All output operations are performed at the end of the file, Append */
        if (debugFile.is_open()) {
            debugFile << "OBJ CAMERA - id: " << Camera::id << std::endl;
            debugFile << "OBJ CAMERA - saveFlag: " << Camera::saveFlag << std::endl;
            debugFile << "OBJ CAMERA - hmin: " << Camera::hmin << std::endl;
            debugFile << "OBJ CAMERA - smin: " << Camera::smin << std::endl;
            debugFile << "OBJ CAMERA - vmin: " << Camera::vmin << std::endl;
            debugFile << "OBJ CAMERA - hmax: " << Camera::hmax << std::endl;
            debugFile << "OBJ CAMERA - smax: " << Camera::smax << std::endl;
            debugFile << "OBJ CAMERA - vmax: " << Camera::vmax << std::endl;
            debugFile.close();
        }
        else
        {
            std::cout << "ERROR: Cannot open the log file" << std::endl;
        }
    }
};


void Camera::getContours(Mat imgGray, Mat img) {

    Mat imgGaussian, imgCanny, imgDil;
    GaussianBlur(imgGray, imgGaussian, Size(3,3),3,0); /* Input, output, size, sigmaX, SigmaY*/ 
    Canny(imgGaussian, imgCanny, 25, 60);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
    dilate(imgCanny, imgDil, kernel);

    std::vector<std::vector<Point> > contours;
    std::vector<Vec4i> hierarchy;
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    std::vector<std::vector<Point> > contours_poly( contours.size() );
    std::vector<Point2f>centers( contours.size() );
    std::vector<float>radius( contours.size() );

    Scalar color = Scalar( rng.uniform(255, 255), rng.uniform(255,255), rng.uniform(255,255) );
/*
    for( size_t i = 0; i < contours.size(); i++ )
    {
        approxPolyDP( contours[0], contours_poly[0], 3, true );
        minEnclosingCircle( contours_poly[0], centers[0], radius[0] );
        std::cout << "Circulo" << centers[0] << (int)radius[0] << std::endl;

        circle(img, centers[0], (int)radius[0], color, FILLED );
    }*/

    /* ONLY FOR TESTING!!! TODO */
    cv::Point2f pt(701.274, 360.274);
    circle(img, pt, 331, color, FILLED );

}
