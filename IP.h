#pragma once
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

//float e=2.71828182846;
//float pi=3.1415926;

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

	enum class histype {
		horizontal,
		vertical,
	};

	namespace Fre {

	};

	namespace Spa {
		cv::Mat Padding(cv::Mat srcimage, int size);
		cv::Mat Gaussian(cv::Mat srcimage, int size, int sigma);
		cv::Mat Sobel(cv::Mat srcimage, int size, int scale, int delta, int ddepth);
	};

	namespace GeoTrans {
		cv::Mat trapezoidal(cv::Mat srcimage, cv::Point2f src[], cv::Point2f dst[]);
        cv::Mat wavy(cv::Mat srcimage, int magnitude, int period);
		cv::Mat circular(cv::Mat srcimage);
	};

	class OMR {
		public:
			OMR(cv::Mat binaryimage);
			~OMR();
			int note_nums;
			int line_nums;
			int sol_nums;

			int** note_xy;
			int* line_y;

			cv::Mat LineRemoved();
			cv::Mat HorizontalProjection();
			cv::Mat TemplateMatching(cv::Mat lineremoveimage, cv::Mat template_image);
			cv::Mat StaffLineRecognition();
			cv::Mat DrawNotePoint(cv::Mat colorimage);
			int** NotePoint(cv::Mat binary_templatematchingimage);
			int* LineLocation(cv::Mat stafflineimage);
			char* Semantics(int y1, int y2, int y3, int y4, int y5);
		private:
			// int* PointCoord(cv::Mat binaryimage, int x, int y);
			cv::Mat binaryimage;
			int x;
			int y;
			void PointCoord(cv::Mat binary_templatematchingimage, int x, int y);
			void LineCoord(cv::Mat binaryimage, int y);
			int* x_y_num_sum; // x_sum, y_sum, num_sum
			int* y_num_sum;
			int template_x;
			int template_y;
			

			

	};

	cv::Mat resize(cv::Mat srcimage, float scale, channel c);
	cv::Mat calchistogram(cv::Mat srcimage, int bin, int binscale);
	cv::Mat hisequalization(cv::Mat srcimage, int bin, int scale);
	cv::Mat Binary(cv::Mat srcimage, int threshold);
	cv::Mat cvtcolor(cv::Mat srcimage, colorconvertcode type);
    cv::Mat pseudocolor(cv::Mat srcimage,float phase_shift);
    cv::Mat colortable(float phase_shift);
	cv::Mat Kmeans_cluster(cv::Mat srcimage, int k,int max_iter);
    cv::Mat HoughTransform(cv::Mat srcimage, cv::Mat binaryimage, int num);
	
	float h(float q);
	void sort(int *arr,int *arr1, int *arr2);

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
		void resize(int re_x, int re_y);
		void show(std::string name);
	private:
		int cols;
		int rows;
		image_color type;
		int*** pixels;
};
