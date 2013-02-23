#ifndef PGMIMAGE
#define PGMIMAGE

#include "pgmImage.h"
#include "ReadImage.cpp"
#include "WriteImage.cpp"
#include <iostream>


PGMImage::PGMImage(const char * & filename){
	image = NULL;
	ReadImage(filename, &image, w, h, q);
}
PGMImage::PGMImage(){
	image = NULL;
	w = 0;
	h = 0;
	q = 0;
	gM = NULL;
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
	WriteImage(filename, image, w, h, q);
}
PGMImage * PGMImage::gaussian(int maskSize){
	
	gM = new float[maskSize];
	return this;
}

#endif