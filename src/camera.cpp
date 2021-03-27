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
    randomNumber = (std::rand() % 20) + 1;  /* To get random images */

    std::string filename = "../test/img/" + std::to_string(randomNumber) + ".jpg";
    Mat img = imread(filename);   /* Mat it is the matrix for the image */
    Mat imgHR, mask, imgGray, imgCircle;
    cvtColor(img, imgHR, COLOR_BGR2HSV); /* Tranform the image to cvtColor */
    Scalar lower(Camera::hmin, Camera::smin, Camera::vmin);
    Scalar upper(Camera::hmax, Camera::smax, Camera::vmax);
    inRange(imgHR, lower, upper, mask); /* Set a range: img, startColor, endColor, mask */
    mask.copyTo(imgCircle);
    getContours(mask,imgCircle);

    int totalNumberCirc = countNonZero(imgCircle);
    int whitePixels = countNonZero(mask);
    int percentageResult = 100 - (int)((whitePixels*100)/totalNumberCirc);

    std::cout << "White: " << whitePixels << std::endl;
    std::cout << "Total: " << totalNumberCirc << std::endl;
    std::cout << "Image:" << randomNumber << " Percentage:" << percentageResult << std::endl;

    std::string strResult = std::to_string(percentageResult) + "%";

    putText(img, strResult, Point(100,100), 
        FONT_HERSHEY_SIMPLEX , 3, Scalar(0,255,0), 3, false);

    // Get dimension of final image
    int rows = max(img.rows, mask.rows) + 10;
    int cols = img.cols + mask.cols + 10;
    // Create a black image
    Mat3b res(rows, cols, Vec3b(0,0,0));

    cvtColor(mask, mask, COLOR_GRAY2RGB ); /* Tranform the image to cvtColor */
    mask.copyTo(res(Rect(0, 0, mask.cols, mask.rows)));
    img.copyTo(res(Rect(mask.cols, 0, img.cols, img.rows)));
    resize(res, res, Size(1000,500), 0, 0, INTER_NEAREST );
    imshow("Result", res);

    
    //filename = "../o.jpg";
    //imwrite(filename, res);

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
    bool findPlate = false;
    if (contours.size() < 1)
    {
        approxPolyDP( contours[0], contours_poly[0], 3, true );
        int objCor = (int)contours_poly[0].size();
        if (objCor > 4)
        {
            minEnclosingCircle( contours_poly[0], centers[0], radius[0] );
            circle(img, centers[0], (int)radius[0], color, FILLED );
            findPlate = true;
        }
    }

    if (findPlate == false)
    {
        /* Don't find the plate...Try with a fix circle size to get a approximate value
           - The idea is log this problem and in future version find a way to get a better result */
        cv::Point2f pt(595, 563); /* Center point */
        circle(img, pt, 540, color, FILLED ); /* A circle */
    }

}
