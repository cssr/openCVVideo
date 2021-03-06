
#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion

#include <opencv2/core.hpp>     // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc.hpp>  // Gaussian Blur
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>  // OpenCV window I/O

#include "stdafx.h"
#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;


int main()
{
	int frameNum = -1;          // Frame counter
	const string sourceReference = "B:\\DATA\\SylviaRijmer\\Videos\\Solos\\AndreCamposSolo.mp4";

	VideoCapture captRefrnc(sourceReference);

	if (!captRefrnc.isOpened())
	{
		cout << "Could not open reference " << sourceReference << endl;
		return -1;
	}
	const char* WIN_RF = "Reference";
	// Windows
	namedWindow(WIN_RF, WINDOW_AUTOSIZE);
	//moveWindow(WIN_RF, 400, 0);
	Mat frameReference;
	for (;;) //Show the image captured in the window and repeat
	{
		captRefrnc >> frameReference;
		if (frameReference.empty())
		{
			cout << " < < <  Game over!  > > > ";
			break;
		}
		++frameNum;
		cout << "Frame: " << frameNum << "# ";
		cout << endl;
		imshow(WIN_RF, frameReference);
		//char c = (char)waitKey(delay);
		//if (c == 27) break;
	}

    return 0;
}

