#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<string.h>

#define nHeight 512
#define nWidth 512

using namespace std;

class Contrast
{
private:
	unsigned char** Image_In;
	unsigned char** Image_Out;
public:
	Contrast();
	~Contrast();
	void ImageOpen();
	double Contrast_Stretch(int x);
	void ImageContrast();
	void ImageSave();
};