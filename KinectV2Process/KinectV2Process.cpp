// KinectV2Process.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KinectV2Handler.h"
#include <KinectToVR.h>
#include <sstream>
#include <string>
#include <iostream>
#include <Windows.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

using namespace std;


/*
int main(int argc, char* argv[])
{
    KinectV2Handler kinect;
    //some boolean variables for different functionality within this
    //program
    bool trackObjects = false;
    bool useMorphOps = false;
    //Matrix to store each frame of the webcam feed
    Mat cameraFeed;
    //matrix storage for HSV image
    Mat HSV;
    //matrix storage for binary threshold image
    Mat threshold;
    //x and y values for the location of the object
    int x = 0, y = 0;
    //create slider bars for HSV filtering
    createTrackbars();
    
    kinect.update();

    
    //start an infinite loop where webcam feed is copied to cameraFeed matrix
    //all of our operations will be performed within this loop
    while (1) {
            kinect.putRGBDataIntoMatrix(cameraFeed)) 
                //convert frame from BGR to HSV colorspace
                cvtColor(cameraFeed, HSV, COLOR_BGR2HSV);
                //filter HSV image between values and store filtered image to
                //threshold matrix
                inRange(HSV, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), threshold);
                //perform morphological operations on thresholded image to eliminate noise
                //and emphasize the filtered object(s)
                if (useMorphOps)
                    morphOps(threshold);
                //pass in thresholded frame to our object tracking function
                //this function will return the x and y coordinates of the
                //filtered object
                if (trackObjects)
                    trackFilteredObject(x, y, threshold, cameraFeed);

                //show frames 
                imshow(windowName2, threshold);
                imshow(windowName, cameraFeed);
                imshow(windowName1, HSV);


                //delay 30ms so that screen can refresh.
                //image will not appear without this waitKey() command
                waitKey(30);
            
        }
        else {
            kinect.initialise();
        }
    }

    return 0;
}
*/
int main() {
#ifndef _DEBUG 
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
#endif 
    KinectV2Handler kinect;
    processLoop(kinect);
    return 0;
}
/*
#ifdef _WIN32
// This disables the console window from appearing on windows only if the Project Settings->Linker->System->SubSystem is set to Windows (rather than Console).
int WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCMDShow)
{
    KinectV2Handler kinect;

    processLoop(kinect);

    return 0;
}
#endif
*/