#include "opencv2/opencv.hpp"
#include "opencv2/aruco.hpp"

//using namespace cv;

int main(int argc, char** argv)
{
    cv::VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0)) return 0;


    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    for(;;) {
          cv::Mat frame;
          cap >> frame;

          cv::Mat copy;
          frame.copyTo(copy);
          std::vector<int> ids;
          std::vector<std::vector<cv::Point2f> > corners;
          cv::aruco::detectMarkers(frame, dictionary, corners, ids);

          if (ids.size() > 0)
              cv::aruco::drawDetectedMarkers(copy, corners, ids);
          

          if( frame.empty() ) break; // end of video stream
          cv::imshow("this is you, smile! :)", copy);
          if( cv::waitKey(10) == 27 ) break; // stop capturing by pressing ESC 
    }

    // the camera will be closed automatically upon exit
    //cap.close();
    cap.release();
    return 0;




}
