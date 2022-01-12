// image_processing.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "IP.h"

using namespace std;


int main()
{
	//cv::Mat img = cv::imread("Aiseed.jpg");
	
	//Image image(img, COLOR);
	
	//image.resize(640, 480);
	//std::cerr << "ddd";
	//image.show("resize test");
	//cv::Mat gray_img = IP::cvtcolor(img, IP::RGB2GRAY);
	//float f = 5.04;
	// cv::Mat pseudo_img = IP::pseudocolor(gray_img, f);
	// cv::Mat resize_img = IP::resize(img, 0.5, IP::C3);
	// cv::Mat his = IP::calchistogram(gray_img, 256, 5);
	
	//cv::imshow("test", img);
	//cv::imshow("pseudo", pseudo_img);
	//cv::imshow("test_resize", resize_img);
	//cv::imshow("histogram", his);
	//cv::waitKey(0);

	// As usual we load our source image (src)
	cv::Mat gray;
	cv::Mat image = cv::imread("happy song.jpg"); // Load an image
	// image = IP::resize(image, 2, IP::C3);
	// Check if image is loaded fine
	cv::cvtColor(image, gray, cv::COLOR_RGB2GRAY);
	//image = IP::GeoTrans::circular(image);
	//cv::Mat gray = IP::calchistogram(image, 256, 1);
	gray = IP::Spa::Gaussian(gray, 1, 5);
	cv::Mat binary = IP::Binary(gray, 200);
	cv::Mat his = IP::OMR::HorizontalProjection(binary);
	cv::Mat linere = IP::OMR::LineRemoved(binary);
	// cv::Mat kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));

	
	//cv::erode(linere, linere, kernel);
	//cv::dilate(linere, linere, kernel);

	// cv::Mat re_linere = IP::resize(image, 2, IP::C1);
	/*
	vector<cv::Vec3f> circles;
	cv::HoughCircles(linere, circles, cv::HOUGH_GRADIENT, 1,
		50,  // change this value to detect circles with different distances to each other
		50,10, 1, 20 // change the last two parameters
   // (min_radius & max_radius) to detect larger circles
	);
	for (size_t i = 0; i < circles.size(); i++)
	{
		cv::Vec3i c = circles[i];
		cv::Point center = cv::Point(c[0], c[1]);
		// circle center
		// cv::circle(src, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
		// circle outline
		int radius = c[2];
		cv::circle(image, center, radius, cv::Scalar(255, 0, 255), 1, cv::LINE_AA);
	}

	// image = IP::resize(image, 0.5, IP::C3);
	// linere = IP::resize(linere, 0.5, IP::C1);
	*/
	
	cv::imshow("line_remove", linere);
	cv::imshow("gray", gray);
	cv::imshow("binary", binary);
	cv::imshow("projection", his);
	cv::imshow("original", image);
	

	// image = IP::HoughTransform(image, 60);
	//imshow("test", image);
	cv::waitKey(0);

	return 0;
}

