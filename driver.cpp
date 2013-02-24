
#include <fstream>
#include <stdlib.h>
#include "pgmImage.h"
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

// Gaussian //

int main( int argc, char ** argv){
	// define variables
	const char * orImageFile = argv[1];
	const char * resImageFile = "result.pgm";
	const char * cvResImageFile = "cvResult.pgm";

	int maskSize = atoi(argv[2]);

	PGMImage * orImage;
	PGMImage * resImage;
	PGMImage * cvResImage;
	Mat cvImage = imread(orImageFile, CV_LOAD_IMAGE_UNCHANGED);
	Mat cvImage2;

	cvsmooth(cvImage, cvImage2, CV_GAUSSIAN, 3, 3);

	imwrite( cvResImageFile, cvImage);
	

	orImage = new PGMImage(orImageFile);

	if( maskSize%2 != 1 ){
		cout << "-Error: Mask size must be odd-" << endl;
	}
	else{
		resImage = (*orImage).gaussian(maskSize);
		(*resImage).write(resImageFile);
	}
	delete orImage;
	delete resImage;

	// cvImage = imread(orImageFile, CV_LOAD_IMAGE_UNCHANGED);

	return 0;
}