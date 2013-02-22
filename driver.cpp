
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
	const char * resImageFile = "result.pgm";

	PGMImage * orImage;
	PGMImage * resImage;

	orImage = new PGMImage(orImageFile);
	(*orImage).gaussian(3);
	(*orImage).write(resImageFile);

	// perform 2D Gaussian convolution with 1D masks
// //SUDO//
// 	image = image(orImageFile)
// 	resimage = smooth(image, argv[argc - 1].atoi())
// 	resiamge.write(resImageFile)
// //SUDO//

	return 0;
}