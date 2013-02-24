
#include <fstream>
#include <stdlib.h>
#include "opencv/cv.h"
#include "pgmImage.h"
#include <iostream>

using namespace std;
using namespace cv;

// Gaussian //

int main( int argc, char ** argv){
	// define variables
	const char * orImageFile = argv[1];
	int maskSize = atoi(argv[2]);
	const char * resImageFile = "result.pgm";

	PGMImage * orImage;
	PGMImage * resImage;

	orImage = new PGMImage(orImageFile);

	if( maskSize%2 != 1 ){
		cout << "-Error: Mask size must be odd-" << endl;
	}
	else{
		resImage = (*orImage).gaussian(maskSize);
		(*resImage).write(resImageFile);
	}

	return 0;
}