#ifndef PGMIMAGE
#define PGMIMAGE

#include "pgmImage.h"
#include "ReadImage.cpp"
#include "WriteImage.cpp"
#include "Gauss_masks.c"
#include <iostream>
#include <cmath>


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
	float s = (float)maskSize / 5.0;
	Gauss(s, maskSize, gM);

	//Convolve Image with Mask
	return convolve(gM, maskSize);
}
PGMImage * PGMImage::convolve(float * mask, int size){
	float ** conyImage = new float*[h];
	float ** conxImage = new float*[h];
	int ** resImage = new int*[h];
	PGMImage * result;

	int imgPosition;

	for( int i = 0; i < h; i++ ){
		conyImage[i] = new float[w];
		conxImage[i] = new float[w];
		resImage[i] = new int[w];
	}
	// convolve Gaussian mask in y direction
	for( int i = 0; i < h; i++ ){
		for(int j = 0; j < w; j++ ){
			//Perform Convolution on selected PIXEL
			conyImage[i][j] = 0;
			for( int k = 0; k < size; k++ ){
				imgPosition = i + k - size/2;

				if( imgPosition >= h)
					conyImage[i][j] += (float)image[2 * i - imgPosition][j] * mask[k];
				else
					conyImage[i][j] += (float)image[abs(imgPosition)][j] * mask[k];
			}
		}
	}
	// convolve Gausssian mask transpose x direction
	for( int i = 0; i < h; i++ ){
		for(int j = 0; j < w; j++ ){
			//Perform Convolution on selected PIXEL
			conxImage[i][j] = 0;
			for( int k = 0; k < size; k++ ){
				imgPosition = j + k - size/2;

				if( imgPosition >= w)
					conxImage[i][j] += (float)conyImage[i][abs(2 * j - imgPosition)] * mask[k];
				else
					conxImage[i][j] += (float)conyImage[i][abs(imgPosition)] * mask[k];
			}
		}
	}

	for( int i = 0; i < h; i++)
		for( int j = 0; j < w; j++ )
			resImage[i][j] = (float)conxImage[i][j];

	result->setImage(resImage, w,h,q);
	return result;
}
void PGMImage::setImage(int ** sImage, int sW, int sH, int sQ ){
	image = sImage;
	w = sW;
	h = sH;
	q = sQ;
}

#endif