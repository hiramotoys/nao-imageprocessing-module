#include "CrossStripesCameraSensor.h"
#include <vector>
#include <iostream>

CrossStripesCameraSensor::CrossStripesCameraSensor() : CameraSensor(){
}

CrossStripesCameraSensor::~CrossStripesCameraSensor(){
}

void CrossStripesCameraSensor::updateImage(){
}

void CrossStripesCameraSensor::update(const char *readfilename, const char *writefilename){
    std::cout << "update" << std::endl;
    image = cv::imread(readfilename);
    cv::Mat copyimage;
    //copyimage = image.create(image.rows, image.cols, image.type());
    cv::resize(image, copyimage, image.size());
    int leftX = -1;
    int leftY = -1;
    int r1;
    int g1;
    int b1;
    int r2;
    int g2;
    int b2;
    bool isDetectedLeftEdge = false;
    for(int j = 0 ; j < image.rows - 10; j += 10){ // x search
	for(int i = 0 ; i < image.cols - 3; i += 3){
	    //std::cout << i << " " << j << std::endl;
	    r1 = (int)image.at<unsigned char>(j, i * 3 + 2);
	    g1 = (int)image.at<unsigned char>(j, i * 3 + 1);
	    b1 = (int)image.at<unsigned char>(j, i * 3 + 0);
	    r2 = (int)image.at<unsigned char>(j, (i + 3) * 3 + 2);
	    g2 = (int)image.at<unsigned char>(j, (i + 3) * 3 + 1);
	    b2 = (int)image.at<unsigned char>(j, (i + 3) * 3 + 0);
	    cv::Point pos(i, j);
	    if(isGreenToWhite(r1, g1, b1, r2, g2, b2)){
		cv::circle(copyimage, pos, 2, CV_RGB(255, 0, 0), -1);
	    }
	    if(isWhiteToGreen(r1, g1, b1, r2, g2, b2)){
		cv::circle(copyimage, pos, 2, CV_RGB(0, 0, 255), -1);
	    }
	}
    }
    for(int i = 0 ; i < image.cols - 10; i += 10){
	for(int j = 0 ; j < image.rows - 3; j += 3){ // y search
	    r1 = (int)image.at<unsigned char>(j, i * 3 + 2);
	    g1 = (int)image.at<unsigned char>(j, i * 3 + 1);
	    b1 = (int)image.at<unsigned char>(j, i * 3 + 0);
	    r2 = (int)image.at<unsigned char>(j + 3, i * 3 + 2);
	    g2 = (int)image.at<unsigned char>(j + 3, i * 3 + 1);
	    b2 = (int)image.at<unsigned char>(j + 3, i * 3 + 0);
	    cv::Point pos(i, j);
	    if(isGreenToWhite(r1, g1, b1, r2, g2, b2)){
		cv::circle(copyimage, pos, 2, CV_RGB(255, 0, 0), -1);
	    }
	    if(isWhiteToGreen(r1, g1, b1, r2, g2, b2)){
		cv::circle(copyimage, pos, 2, CV_RGB(0, 0, 255), -1);
	    }
	}
    }
    cv::imwrite(writefilename, copyimage);
    std::cout << writefilename << std::endl;
}

void CrossStripesCameraSensor::detectLines(){
}

void CrossStripesCameraSensor::detectBall(){
}

void CrossStripesCameraSensor::detectNao(){
}

void CrossStripesCameraSensor::detectGoal(){
}

bool CrossStripesCameraSensor::isGreenToWhite(int r1, int g1, int b1, int r2, int g2, int b2){
    if(r2 - r1 > 50 && b2 - b1 > 50){
	return true;
    }
    return false;
}

bool CrossStripesCameraSensor::isWhiteToGreen(int r1, int g1, int b1, int r2, int g2, int b2){
    if(r1 - r2 > 50 && b1 - b2 > 50){
	return true;
    }
    return false;
}
