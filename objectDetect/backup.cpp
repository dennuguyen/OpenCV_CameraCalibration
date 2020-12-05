#include "opencv2/opencv.hpp"
#include "opencv2/aruco.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/utility.hpp>
#include <iostream>

//using namespace cv;

int main(int argc, char** argv)
{
    cv::VideoCapture inputVideo;
inputVideo.open(0);
cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
while (inputVideo.grab()) {
    cv::Mat image, imageCopy;
    inputVideo.retrieve(image);
    image.copyTo(imageCopy);
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f> > corners;
    cv::aruco::detectMarkers(image, dictionary, corners, ids);
     //if at least one marker detected
    if (ids.size() > 0) {
        cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
        std::cout << "marker found" << std::endl;
    }

    //std::string image_path = cv::samples::findFile("tags.jpg");
    image = cv::imread( "/home/owr01/OpenCV_CameraCalibration/objectDetect/tags.jpg" );
    cv::aruco::detectMarkers(image, dictionary, corners, ids);
if (ids.size() > 0) {
        //cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
        std::cout << "marker found" << std::endl;
    }
    cv::imshow("out", imageCopy);
    char key = (char) cv::waitKey(10);
    if (key == 27)
        break;
}


return 0;

}
