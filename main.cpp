/* dist_est_stereo_cam::main.cpp ---
 * This program will eventually use multiple cameras to calculate/estimate distance
 * of particular objects. Currently on Ubuntu 16.04, OpenCV3.1. One of my webcams do not have a supported pixel format
 * because probably because OpenCV installation might not be configured to support the required codecs at compile time
 * Must include this line before execution for the program to work with that particular camera:
 * 'LD_PRELOAD="/usr/lib/x86_64-linux-gnu/libv4l/v4l1compat.so"'
 * That is, in terminal:
 * myComputer:/$ LD_PRELOAD="/usr/lib/x86_64-linux-gnu/libv4l/v4l1compat.so" ./dist_est_stereo_cam
 *
 * Author:          Winston Poh
 * Date created:    30 NOV 2016
 * Date modified:   30 NOV 2016
 * */

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
int main()
{
    //initialize and allocate memory to load the video stream from camera
    cv::VideoCapture camera0(0);
    cv::VideoCapture camera1(1);
    cv::VideoCapture camera2(2);

    if( !camera0.isOpened() ) return 1;
    if( !camera1.isOpened() ) return 1;
    if( !camera2.isOpened() ) return 1;

    while(true) {
        //grab and retrieve each frames of the video sequentially
        cv::Mat3b frame0;
        camera0 >> frame0;
        cv::Mat3b frame1;
        camera1 >> frame1;
        cv::Mat3b frame2;
        camera2 >> frame2;

        cv::imshow("Webcam0", frame0);
        cv::moveWindow("Webcam0",1,10);
        cv::imshow("Webcam1", frame1);
        cv::moveWindow("Webcam1",643,10);
        cv::imshow("Webcam2", frame2);
        cv::moveWindow("Webcam2",1278,10);
        //wait for 40 milliseconds
        int c = cvWaitKey(40);

        //exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
        if(27 == char(c)) break;
    }

    return 0;
}