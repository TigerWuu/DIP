#pragma once
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <opencv2/opencv.hpp>



namespace IP {

	enum colorconvertcode {
        RGB2RGB,
		RGB2GRAY,
		RGB2CMY,
		RGB2HSI,
		RGB2XYZ,
		RGB2Lab,
		RGB2YUV,

	};

	enum channel {
		C1,
		C3,
	};



	namespace Fre {

	};

	namespace Spa {

	};


	cv::Mat resize(cv::Mat srcimage, float scale, channel c);
	cv::Mat calchistogram(cv::Mat srcimage, int bin, int binscale);
	cv::Mat hisequalization(cv::Mat srcimage, int bin, int scale);
	cv::Mat cvtcolor(cv::Mat srcimage, colorconvertcode type);
    cv::Mat pseudocolor(cv::Mat srcimage,float phase_shift);
    cv::Mat colortable(float phase_shift);
    cv::Mat Kmeans_cluster(cv::Mat srcimage, int k,int max_iter);
	float h(float q);

};

enum image_color {
	COLOR,
	GRAY,
};

class Image {
	public:
		Image(cv::Mat cv_image, image_color c);
		Image(int x, int y, image_color c);
		~Image();
		Image resize(int re_x, int re_y);
		void show();
	private:
		int cols;
		int rows;
		image_color type;
		int*** pixels;
};
