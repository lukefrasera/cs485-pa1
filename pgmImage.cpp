#ifndef PGMIMAGE
#define PGMIMAGE

#include "pgmImage.h"
#include "ReadImage.cpp"
#include "WriteImage.cpp"
#include <iostream>

PGMImage::PGMImage(const char * & filename){
	image = NULL;
	ReadImage(filename, &image, h, w, q);
	cout << w << h << endl;
}
PGMImage::PGMImage(){
	image = NULL;
	w = 0;
	h = 0;
	q = 0;
}
PGMImage::~PGMImage(){
	if(image != NULL){
		for(int i = 0; i < h; i++){
			delete image[i];
		}
		delete image;
	}
}
bool PGMImage::write(const char * & filename){
	WriteImage(filename, image, h, w, q);
}
PGMImage * PGMImage::gaussian(int maskSize){
	for(int i = 0; i < h; i++){
		for( int j = 0; j < w; j++){
			image[i][j] /= 2;
		}
	}
	return this;
}

#endif