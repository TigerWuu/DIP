#include "IP.h"


namespace IP {
	cv::Mat resize(cv::Mat srcimage, float scale, channel c){
		int x = srcimage.cols;
		int y = srcimage.rows;
		int re_x = x * scale;
		int re_y = y * scale;
		if (c == C1) {
			cv::Mat dstimage = cv::Mat(cv::Size(re_x, re_y), CV_8UC1);
			for (int i = 0; i < re_y; i++) {
				for (int j = 0; j < re_x; j++) {
					dstimage.at<uchar>(i, j) = srcimage.at<uchar>((int)(i / scale), (int)(j / scale));
				}
			}
			return dstimage;
		}
		else if (c == C3) {
			cv::Mat dstimage = cv::Mat(cv::Size(re_x, re_y), CV_8UC3);
			for (int i = 0; i < re_y; i++) {
				for (int j = 0; j < re_x; j++) {
					for (int channel = 0; channel < 3; channel++) {
						dstimage.at<cv::Vec3b>(i, j)[channel] = srcimage.at<cv::Vec3b>((int)(i / scale), (int)(j / scale))[channel];
					}
				}
			}
			return dstimage;
		}	
	}

	cv::Mat calchistogram(cv::Mat srcimage, int bin, int binscale) {

		int x = srcimage.cols;
		int y = srcimage.rows;
		int value = 0;
		int* histdata = new int[bin] {0};
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				value = srcimage.at<uchar>(i, j);
				histdata[value] += 1;
			}
		}
		int height = histdata[0];
		for (int i = 0; i < bin; i++) {
			if (histdata[i] > height) {
				height = histdata[i];
			}
		}
		cv::Mat histimage = cv::Mat(cv::Size(bin * binscale, height), CV_8UC1);

		for (int i = 0; i < bin; i++) {
			for (int j = 0; j < binscale; j++) {
				cv::Point p1(i * binscale + j, height);
				cv::Point p2(i * binscale + j, height - histdata[i]);
				cv::line(histimage, p1, p2, 64);
			}
		}

		cv::resize(histimage, histimage, cv::Size(640,480));
		delete[] histdata;

		return histimage;
	}
	cv::Mat Binary(cv::Mat srcimage, int threshold) {
		int x = srcimage.cols;
		int y = srcimage.rows;
		cv::Mat binaryimage = cv::Mat(cv::Size(x, y), CV_8UC1);
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (srcimage.at<uchar>(i, j) > threshold) {
					binaryimage.at<uchar>(i, j) = 255;
				}
				else {
					binaryimage.at<uchar>(i, j) = 0;
				}
			}
		}
		return binaryimage;
	}

	cv::Mat cvtcolor(cv::Mat srcimage, colorconvertcode type) {
		int x = srcimage.cols;
		int y = srcimage.rows;

		switch (type) {
        case RGB2RGB:
        {
            return srcimage;
        }
		case RGB2GRAY: 
		{
			int R;
			int G;
			int B;
			cv::Mat convertedimage = cv::Mat(cv::Size(x, y), CV_8UC1);
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					R = srcimage.at<cv::Vec3b>(i, j)[0];
					G = srcimage.at<cv::Vec3b>(i, j)[1];
					B = srcimage.at<cv::Vec3b>(i, j)[2];
					convertedimage.at<uchar>(i, j) = (R + G + B) / 3;
				}
			}
			return convertedimage;
		
		}
			
		case RGB2CMY:
		{
			cv::Mat convertedimage = cv::Mat(cv::Size(x, y), CV_8UC3);
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					for (int channel = 0; channel < 3; channel++) {
                        // CMY = 1-RGB
						convertedimage.at<cv::Vec3b>(i, j)[channel] = 255 - srcimage.at<cv::Vec3b>(i, j)[channel];
					}
				}
			}
			return convertedimage;
		}
			
		case RGB2HSI:
		{
			cv::Mat convertedimage = cv::Mat(cv::Size(x, y), CV_8UC3);
			float theta = 0;
			int R = 0;
			int G = 0;
			int B = 0;
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
                    // reference textbook p.413
					R = srcimage.at<cv::Vec3b>(i, j)[0];
					G = srcimage.at<cv::Vec3b>(i, j)[1];
					B = srcimage.at<cv::Vec3b>(i, j)[2];
					theta = acos((1.0 / 2.0 * (R - G + R - B)) / pow((pow((R - G), 2) + (R - B) * (G - B)), 2));
					if (B <= G) {
						convertedimage.at<cv::Vec3b>(i, j)[0] = theta/360.0*255;
					}
					else {
						convertedimage.at<cv::Vec3b>(i, j)[0] = (360-theta) / 360.0 * 255;
					}
					convertedimage.at<cv::Vec3b>(i, j)[1] = (1 - 3.0 / (R + G + B) * std::min({ R, G, B })) * 255;
					convertedimage.at<cv::Vec3b>(i, j)[2] = (R + G + B) / 3;
				}
			}
			return convertedimage;
		}
		case RGB2XYZ:
		{
			int X = 0;
			int Y = 0;
			int Z = 0;
			int R = 0;
			int G = 0;
			int B = 0;
			cv::Mat convertedimage = cv::Mat(cv::Size(x, y), CV_8UC3);
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					R = srcimage.at<cv::Vec3b>(i, j)[0];
					G = srcimage.at<cv::Vec3b>(i, j)[1];
					B = srcimage.at<cv::Vec3b>(i, j)[2];

					X = 0.412 * R + 0.357 * G + 0.180 * B;
					Y = 0.212 * R + 0.715 * G + 0.072 * B;
					Z = 0.019 * R + 0.119 * G + 0.950 * B;

					convertedimage.at<cv::Vec3b>(i, j)[0] = X;
					convertedimage.at<cv::Vec3b>(i, j)[1] = Y;
					convertedimage.at<cv::Vec3b>(i, j)[2] = Z;
				}
			}
			return convertedimage;

		}

		case RGB2Lab:
		{
			cv::Mat convertedimage;
			convertedimage = cvtcolor(srcimage, RGB2XYZ);
			int L = 0;
			int a = 0;
			int b = 0;
			float Xw = 95.05;
			float Yw = 100.0;
			float Zw = 108.89;
			int X = 0;
			int Y = 0;
			int Z = 0;

			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					X = convertedimage.at<cv::Vec3b>(i, j)[0];
					Y = convertedimage.at<cv::Vec3b>(i, j)[1];
					Z = convertedimage.at<cv::Vec3b>(i, j)[2];
					
					L = (116 * h(Y / Yw) - 16)/100.0*255.0;// normalize from (0,100) to (0,255)
					a = (500 * (h(X / Xw) - h(Y / Yw))+500)/1000.0*255.0;// normalize from (-500,500) to (0,255)
					b = (200 * (h(Y / Yw) - h(Z / Zw))+200)/400.0*255.0;// normalize from (-200,200) to (0,255)

					convertedimage.at<cv::Vec3b>(i, j)[0] = L;
					convertedimage.at<cv::Vec3b>(i, j)[1] = a;
					convertedimage.at<cv::Vec3b>(i, j)[2] = b;
				}
			}
			return convertedimage;

		}
		case RGB2YUV:
		{
			int Y = 0;
			int U = 0;
			int V = 0;
			int R = 0;
			int G = 0;
			int B = 0;
			cv::Mat convertedimage = cv::Mat(cv::Size(x, y), CV_8UC3);
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					R = srcimage.at<cv::Vec3b>(i, j)[0];
					G = srcimage.at<cv::Vec3b>(i, j)[1];
					B = srcimage.at<cv::Vec3b>(i, j)[2];

					Y =  0.299 * R + 0.587 * G + 0.114 * B;
					U = -0.169 * R - 0.331 * G + 0.500 * B + 128;
					V =  0.500 * R - 0.419 * G - 0.081 * B + 128;

					convertedimage.at<cv::Vec3b>(i, j)[0] = Y;
					convertedimage.at<cv::Vec3b>(i, j)[1] = U;
					convertedimage.at<cv::Vec3b>(i, j)[2] = V;
				}
			}
			return convertedimage;
		}

        default://RGB
            std::cout << "Wrong converted code!";
            return srcimage;
        }
	}

	float h(float q) {
		if (q > 0.008856) {
			return pow(q, 1 / 3);
		}
		else {
			return 7.787 * q + 16.0 / 116.0;
		}
	}

	void sort(int *arr, int *arr1, int *arr2){
		int length = sizeof(arr) / sizeof(arr[0]);
		int max = arr[0];
		for (int i = 0; i < length; i++) {
			if (arr[i] > max) {
				;
			}
		}
	}

    cv::Mat pseudocolor(cv::Mat srcimage,float phase_shift) {
		int x = srcimage.cols;
		int y = srcimage.rows;
        float pi=3.1415926;

		cv::Mat dstimage = cv::Mat(cv::Size(x, y), CV_8UC3);
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
                // create sin wave
                // +1 to avoid the negative number *127 to normalize to (0,255)
                dstimage.at<cv::Vec3b>(i, j)[0] = (int)(127 * (sin(srcimage.at<uchar>(i, j)*2*pi/255.0)+1));
                dstimage.at<cv::Vec3b>(i, j)[1] = (int)(127 * (sin(srcimage.at<uchar>(i, j)*2*pi/255.0+phase_shift)+1));
                dstimage.at<cv::Vec3b>(i, j)[2] = (int)(127 * (sin(srcimage.at<uchar>(i, j)*2*pi/255.0+phase_shift*2)+1));
			}
		}
		return dstimage;
	}

    cv::Mat colortable(float phase_shift){
        int x = 1;
        int y = 256;
        float pi=3.1415926;

        cv::Mat dstimage = cv::Mat(cv::Size(x,y),CV_8UC3);

        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                dstimage.at<cv::Vec3b>(i, j)[0] = (int)(127 * (sin((255-i)*2*pi/255.0)+1));
                dstimage.at<cv::Vec3b>(i, j)[1] = (int)(127 * (sin((255-i)*2*pi/255.0+phase_shift)+1));
                dstimage.at<cv::Vec3b>(i, j)[2] = (int)(127 * (sin((255-i)*2*pi/255.0+phase_shift*2)+1));
            }
        }
        return dstimage;
    }

    cv::Mat Kmeans_cluster(cv::Mat srcimage, int k, int max_iter){
        int x = srcimage.cols;
        int y = srcimage.rows;
        cv::Mat dstimage = cv::Mat(cv::Size(1,x*y),CV_32FC3);
        cv::Mat labels;
        cv::Mat centers;
        cv::Mat points = srcimage.reshape(1,x*y);

        points.convertTo(points,CV_32F);

        int flags = cv::KMEANS_RANDOM_CENTERS ;
        cv::TermCriteria criteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, max_iter, 1.0);

        cv::kmeans(points, k, labels, criteria, 3, flags, centers);

        for(int i=0;i<x*y;i++){
            dstimage.at<cv::Vec3f>(i,0)[0] = centers.at<float>((labels.at<int>(i,0)),0);
            dstimage.at<cv::Vec3f>(i,0)[1] = centers.at<float>((labels.at<int>(i,0)),1);
            dstimage.at<cv::Vec3f>(i,0)[2] = centers.at<float>((labels.at<int>(i,0)),2);
        }
        dstimage = dstimage.reshape(3,y);
        dstimage.convertTo(dstimage,CV_8U);
        return dstimage;
    }
    cv::Mat HoughTransform(cv::Mat srcimage, cv::Mat binaryimage, int num) {
        //num != 0
        if(num == 0){return srcimage ;}
		// accumulate rou-theta plane value 
		int** rou_theta_plane = new int* [180];
		int max_rou = pow(pow(binaryimage.cols, 2) + pow(binaryimage.rows, 2), 0.5);
		int rou = 0;

		for (int theta = 0; theta < 180; theta++) {
			rou_theta_plane[theta] = new int[2 * max_rou]{ 0 };
		}

		for (int x = 0; x < binaryimage.cols; x++) {
			for (int y = 0; y < binaryimage.rows; y++) {
				if (binaryimage.at<uchar>(y, x) == 255) {
					for (int theta = 0; theta < 180; theta++) {
						// see page 739, x and y axis is reverse
						rou = int(x * cos(theta) + y * sin(theta));
						// scale (-D,D) to (0,2D)
						rou += max_rou;
						// std::cerr << rou << std::endl;
						rou_theta_plane[theta][rou] += 1;
					}
				}
			}
		}
		// find the top num bigger numbers in the rou_theta_plane
		int** max = new int* [num];

		for (int i = 0; i < num; i++) {
			max[i] = new int[3];
		}
		for (int i = 0; i < num; i++) {
			max[i][0] = rou_theta_plane[0][0];
			max[i][1] = 0; // theta
			max[i][2] = i; // rou
		}
		// sort (need to improve)
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num-1; j++) {
				if (max[j][0] < max[j + 1][0]) {
					int* temp = max[j];
					max[j] = max[j + 1];
					max[j + 1] = temp;
				}
			}
		}
		for (int theta = 0; theta < 180; theta++) {
			for (int rou = 0; rou < 2 * max_rou; rou++) {
				if (rou_theta_plane[theta][rou] > max[num-1][0]) {
					max[num - 1][0] = rou_theta_plane[theta][rou];
					max[num - 1][1] = theta;
					max[num - 1][2] = rou;
				}
				// sort (need to improve)
				for (int i = 0; i < num; i++) {
					for (int j = 0; j < num - 1; j++) {
						if (max[j][0] < max[j + 1][0]) {
							int* temp = max[j];
							max[j] = max[j + 1];
							max[j + 1] = temp;
						}
					}
				}
			}
		}

		// plot the line on the srcimage
		float a = 0;
		float b = 0;
		for (int i = 0; i < num; i++) {
			a = -cos(max[i][1]) / sin(max[i][1]);
			b = (max[i][2]-max_rou) / sin(max[i][1]);
			//std::cout << a << std::endl;
			//std::cout << b << std::endl;
			int x = srcimage.cols;
			int y = 0;
			y = a * x + b;
			cv::Point p1(x, y);
			x = 0;
			y = a * x + b;
			cv::Point p2(x, y);
			//std::cout << -b / a << std::endl;
			//std::cout << b << std::endl;
			cv::line(srcimage, p1, p2, cv::Scalar(255,255,255),1);
		}
		

		for (int theta = 0; theta < 180; theta++) {
			delete[] rou_theta_plane[theta];
		}
		delete [] rou_theta_plane;
		return srcimage;
	}
	namespace Spa {
          cv::Mat Padding(cv::Mat srcimage, int size) {
			int x = srcimage.cols;
			int y = srcimage.rows;
			int edge = (size - 1) / 2;

			cv::Mat image_padding = cv::Mat(cv::Size(x + size - 1, y + size - 1), CV_8UC1);
			for (int i = edge; i < image_padding.rows - edge; i++) {
				for (int j = edge; j < image_padding.cols - edge; j++) {
					image_padding.at<uchar>(i, j) = srcimage.at<uchar>(i - edge, j - edge);
				}
			}
			return image_padding;
		}

		cv::Mat Gaussian(cv::Mat srcimage, int size, int sigma) {
			int x = srcimage.cols;
			int y = srcimage.rows;
			int weight = 0;
			int sum = 0;
            float e=2.71828182846;

			cv::Mat image_gaussian = cv::Mat(cv::Size(x, y), CV_8UC1);
			cv::Mat mask = cv::Mat(cv::Size(size, size), CV_32FC1);
			// create a padding image //
			cv::Mat image_padding = Padding(srcimage, size);

			for (int s = 0; s < mask.rows; s++) {
				for (int t = 0; t < mask.cols; t++) {
					mask.at<float>(s, t) = pow(e, -((s * s + t * t) / (2 * sigma * sigma)));
					weight += mask.at<float>(s, t);
				}
			}

			for (int i = 0; i < image_gaussian.rows; i++) {
				for (int j = 0; j < image_gaussian.cols; j++) {
					sum = 0;
					for (int a = 0; a < size; a++) {
						for (int b = 0; b < size; b++) {
							sum += mask.at<float>(a, b) * image_padding.at<uchar>(a + i, b + j);
						}
					}
					image_gaussian.at<uchar>(i, j)= 1.0 / weight * sum;
				}
			}
			return image_gaussian;
		}
		cv::Mat Sobel(cv::Mat srcimage, int size, int scale, int delta, int ddepth) {
			cv::Mat grad_x, grad_y, grad;
			cv::Mat abs_grad_x, abs_grad_y;
			cv::Sobel(srcimage, grad_x, ddepth, 1, 0, size, scale, delta, cv::BORDER_DEFAULT);
			cv::Sobel(srcimage, grad_y, ddepth, 0, 1, size, scale, delta, cv::BORDER_DEFAULT);
			// converting back to CV_8U
			convertScaleAbs(grad_x, abs_grad_x);
			convertScaleAbs(grad_y, abs_grad_y);
			addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
			return grad;
		}
	};

	namespace GeoTrans {
        cv::Mat trapezoidal(cv::Mat srcimage, cv::Point2f src[], cv::Point2f dst[]) {
			cv::Mat warpimage;
			cv::Mat warpmat;
			warpmat = cv::getPerspectiveTransform(src, dst);
			cv::warpPerspective(srcimage, warpimage, warpmat, srcimage.size());
			return warpimage;
		}
        cv::Mat wavy(cv::Mat srcimage, int magnitude, int period) {
            int x = srcimage.cols;
            int y = srcimage.rows;
            float pi=3.1415926;
            int mag = magnitude;
            int per = period;

            cv::Mat wavyimage = cv::Mat::zeros(y, x, CV_8UC3);
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    int u = mag * sin(2 * pi * i / per) + j; // new x
                    int v = mag * sin(2 * pi * j / per) + i; // new y
                    if (v > 0 && v < y && u > 0 && u < x) {
                        wavyimage.at<cv::Vec3b>(i, j)[0] = srcimage.at<cv::Vec3b>(v, u)[0];
                        wavyimage.at<cv::Vec3b>(i, j)[1] = srcimage.at<cv::Vec3b>(v, u)[1];
                        wavyimage.at<cv::Vec3b>(i, j)[2] = srcimage.at<cv::Vec3b>(v, u)[2];
                    }
                }
            }
			return wavyimage;
		}
		cv::Mat circular(cv::Mat srcimage) {
			int x = srcimage.cols;
			int y = srcimage.rows;
			cv::Mat circularimage = cv::Mat::zeros(y, x, CV_8UC3);
			cv::Mat row = cv::Mat(cv::Size(x, 1), CV_8UC3);
			cv::Mat resize_row;
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					for (int channel = 0; channel < 3; channel++) {
						row.at<cv::Vec3b>(0, j)[channel] = srcimage.at<cv::Vec3b>(i, j)[channel];
					}
				}

				int resize_x = 2 * pow((pow(y / 2, 2) - pow(y / 2 - i, 2)), 0.5);
				// std::cerr << resize_x<<std::endl;
				if (resize_x != 0) {
					cv::resize(row, resize_row, cv::Size(resize_x, 1));
					for (int ii = 0; ii < resize_x; ii++) {
						for (int channel = 0; channel < 3; channel++) {
							circularimage.at<cv::Vec3b>(i, ((x - resize_x) / 2 + ii))[channel] = resize_row.at<cv::Vec3b>(0, ii)[channel];
						}
					}
				}
			}
			return circularimage;
		}
	};

	OMR::OMR(cv::Mat binaryimage) {
		this->binaryimage = binaryimage.clone();
		this->x = binaryimage.cols;
		this->y = binaryimage.rows;
		this->x_y_num_sum = new int[3]{ 0 };
		this->y_num_sum = new int[2]{ 0 };
        this->note_xy = new int* [2];

		this->note_nums = 0;
		this->line_nums = 0;
		this->sol_nums = 0;
	}
	OMR::~OMR() {
        delete[] this->x_y_num_sum;
        delete[] this->y_num_sum;

        /*
		for (int i = 0; i < 2; i++) {
			delete[] this->note_xy[i];
		}
        delete[] this->note_xy;
        */
	}

	cv::Mat OMR::HorizontalProjection() {

		int value = 0;
		int* histdata = new int[y] {0};
		for (int i = 0; i < y; i++) {
			value = 0;
			for (int j = 0; j < x; j++) {
				if (binaryimage.at<uchar>(i, j) == 0) { value += 1; }
			}
			histdata[i] = value;
		}

		cv::Mat histimage = cv::Mat(binaryimage.size(), CV_8UC1);

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cv::Point p1(0, i);
				cv::Point p2(histdata[i], i);
				cv::line(histimage, p1, p2, 64);
			}
		}

		delete[] histdata;

		return histimage;
	}

	cv::Mat OMR::TemplateMatching(cv::Mat lineremoveimage, cv::Mat template_image) {
		this->template_x = template_image.cols;
		this->template_y = template_image.rows;

		cv::Mat templatematchingimage;
		cv::cvtColor(template_image, template_image, cv::COLOR_RGB2GRAY);
		cv::matchTemplate(lineremoveimage, template_image, templatematchingimage, cv::TM_CCORR_NORMED);
		cv::normalize(templatematchingimage, templatematchingimage, 0, 255, cv::NORM_MINMAX);
		templatematchingimage = cv::Mat_<uchar>(templatematchingimage);
		return templatematchingimage;
	}

	cv::Mat OMR::StaffLineRecognition() {
		int value = 0;
		int* histdata = new int[y] {0};
		for (int i = 0; i < y; i++) {
			value = 0;
			for (int j = 0; j < x; j++) {
				if (binaryimage.at<uchar>(i, j) == 0) { value += 1; }
			}
			histdata[i] = value;
		}

		cv::Mat stafflineimage = binaryimage.clone();
		for (int i = 0; i < y; i++) {
			if (histdata[i] > x / 2) {
				for (int j = 0; j < x; j++) {
					stafflineimage.at<uchar>(i, j) = 0;
				}
			}
			else {
				for (int j = 0; j < x; j++) {
					stafflineimage.at<uchar>(i, j) = 255;
				}
			}
		}
        delete[] histdata;

		return stafflineimage;

	}

	cv::Mat OMR::LineRemoved() {
		int value = 0;
		int* histdata = new int[y] {0};

		cv::Mat dstimage = binaryimage.clone();
		for (int i = 0; i < y; i++) {
			value = 0;
			for (int j = 0; j < x; j++) {
				if (binaryimage.at<uchar>(i, j) == 0) { value += 1; }
			}
			histdata[i] = value;
		}
		for (int i = 0; i < y; i++) {
			if (histdata[i] > x / 2) {
				for (int j = 0; j < x; j++) {
                    if (i < (y-2) && i>2){
                        if (!(binaryimage.at<uchar>(i + 1, j) == 0 && binaryimage.at<uchar>(i + 2, j) == 0 && binaryimage.at<uchar>(i - 1, j) == 0 && binaryimage.at<uchar>(i - 2, j) == 0)) {
                            dstimage.at<uchar>(i, j) = 255;
                        }
                    }
				}
			}
		}
        delete[] histdata;

		return dstimage;
	}

	int** OMR::NotePoint(cv::Mat binary_templatematchingimage) {

		cv::Mat binary_templatematchingimage2 = binary_templatematchingimage.clone();

		int x = binary_templatematchingimage2.cols;
		int y = binary_templatematchingimage2.rows;

			
		std::vector<int> note_x;
		std::vector<int> note_y;
		
		// sort. So rows firt, then cols
		for (int j = 0; j < x; j++) {
			for (int i = 0; i < y; i++) {
				if (binary_templatematchingimage2.at<uchar>(i, j) == 255) {
					// clear x_y_num_sum
					for (int i = 0; i < 3; i++) { this->x_y_num_sum[i] = 0; }
					PointCoord(binary_templatematchingimage2, j, i);
					note_x.push_back(this->x_y_num_sum[0] / this->x_y_num_sum[2]);
					note_y.push_back(this->x_y_num_sum[1] / this->x_y_num_sum[2]);
					note_nums++;
					//cv::imshow("result", binaryimage);
					//cv::waitKey(0);
					//std::cout << "------------------" << std::endl;
				}
		
			}
		}
		for (int i = 0; i < 2; i++) {
			this->note_xy[i] = new int[this->note_nums];
		}
		for (int i = 0; i < this->note_nums; i++) {
			this->note_xy[0][i] = note_x[i];
			this->note_xy[1][i] = note_y[i];
		}
		// std::cout << note_nums << std::endl;
		return this->note_xy;
	}

	/*
	int* CP::PointCoord(cv::Mat binaryimage, int x, int y) {
		int* x_y = new int[2]{x ,y};
		if (binaryimage.at<uchar>(y, x + 1) == 255) {
			x_y = PointCoord(binaryimage, x + 1, y);
			this->x_y_num_sum[0] += x_y[0];
			this->x_y_num_sum[1] += x_y[1];
			this->x_y_num_sum[2] += 1;
		}
		if (binaryimage.at<uchar>(y, x - 1) == 255) {
			x_y = PointCoord(binaryimage, x + 1, y);
			this->x_y_num_sum[0] += x_y[0];
			this->x_y_num_sum[1] += x_y[1];
			this->x_y_num_sum[2] += 1;
		}
		if (binaryimage.at<uchar>(y + 1, x) == 255) {
			x_y = PointCoord(binaryimage, x + 1, y);
			this->x_y_num_sum[0] += x_y[0];
			this->x_y_num_sum[1] += x_y[1];
			this->x_y_num_sum[2] += 1;
		}
		if (binaryimage.at<uchar>(y - 1, x + 1) == 255) {
			x_y = PointCoord(binaryimage, x + 1, y);
			this->x_y_num_sum[0] += x_y[0];
			this->x_y_num_sum[1] += x_y[1];
			this->x_y_num_sum[2] += 1;
		}
			

		return x_y;
	}
	*/
	void OMR::PointCoord(cv::Mat binary_templatematchingimage, int x, int y) {
		this->x_y_num_sum[0] += x;
		this->x_y_num_sum[1] += y;
		this->x_y_num_sum[2] += 1;
		binary_templatematchingimage.at<uchar>(y, x) = 0;
		if (x != binary_templatematchingimage.cols && y != binary_templatematchingimage.rows) {
			if (binary_templatematchingimage.at<uchar>(y, x + 1) == 255) {
				PointCoord(binary_templatematchingimage, x + 1, y);
				//std::cout << "1" << std::endl;
			}
			if (binary_templatematchingimage.at<uchar>(y, x - 1) == 255) {
				PointCoord(binary_templatematchingimage, x - 1, y);
				//std::cout << "2" << std::endl;
			}
			if (binary_templatematchingimage.at<uchar>(y + 1, x) == 255) {
				PointCoord(binary_templatematchingimage, x, y+1);
				//std::cout << "3" << std::endl;
			}
			if (binary_templatematchingimage.at<uchar>(y - 1, x ) == 255) {
				PointCoord(binary_templatematchingimage, x, y-1);
				//std::cout << "4" << std::endl;
			}
		}
	}
	cv::Mat OMR::DrawNotePoint(cv::Mat colorimage) {
		cv::Mat Notepoint_image = colorimage.clone();
		for (int i = 0; i < this->note_nums; i++) {
			int x_shift = this->template_x / 2;
			int y_shift = this->template_y - 8;
			cv::Point center = cv::Point(this->note_xy[0][i] + x_shift, this->note_xy[1][i] + y_shift);
            cv::circle(Notepoint_image, center, 1, cv::Scalar(255, 0, 0), 1, cv::LINE_AA);
		}
		return Notepoint_image;
	}

	int* OMR::LineLocation(cv::Mat stafflineimage) {
		std::vector<int> line_y_temp;
		cv::Mat stafflineimage2 = stafflineimage.clone();

		for (int i = 0; i < y; i++) {
			// clear y_num_sum
			for (int i = 0; i < 2; i++) { this->y_num_sum[i] = 0; }

			if (stafflineimage2.at<uchar>(i,0) == 0) {
				LineCoord(stafflineimage2, i);
				line_y_temp.push_back(this->y_num_sum[0] / this->y_num_sum[1]);
				this->line_nums++;
			}
		}
		this->line_y = new int[line_nums] {0};
		for (int i = 0; i < this->line_nums; i++) {
			this->line_y[i] = line_y_temp[i];
			//std::cout << line_y[i] << std::endl;
		}
		return this->line_y;
	}

	void OMR::LineCoord(cv::Mat stafflineimage, int y) {
		this->y_num_sum[0] += y;
		this->y_num_sum[1] += 1;

		stafflineimage.at<uchar>(y, 0) = 255;
        if (y != stafflineimage.rows-1) {
			if (stafflineimage.at<uchar>(y + 1, 0) == 0) {
				LineCoord(stafflineimage, y + 1);
			}
		}
	}

	char* OMR::Semantics(int y1, int y2, int y3, int y4, int y5) {
		float gap = y2 - y1;
		float quarter_gap = gap / 4;
		int y_shift = this->template_y - 8;
		std::vector<int> note_y;
		this->sol_nums = 0;

		for (int i = 0; i < this->note_nums; i++) {
			if ((this->note_xy[1][i]+ y_shift < (y5 + gap + quarter_gap)) && (this->note_xy[1][i]+ y_shift > (y1 - gap - quarter_gap))) {

				note_y.push_back((this->note_xy[1][i])+ y_shift);
				this->sol_nums++;
			}
		}
        char* solmizations = new char[this->sol_nums+1]{};

		for (int i = 0; i < this->sol_nums; i++) {
			if (note_y[i] >= y1 - gap - quarter_gap && note_y[i] <= y1 - gap + quarter_gap) { solmizations[i] = 'A'; }
			else if (note_y[i] > y1 - gap + quarter_gap && note_y[i] <= y1 - quarter_gap) { solmizations[i] = 'G'; }
			else if (note_y[i] > y1 - quarter_gap && note_y[i] <= y1 + quarter_gap) { solmizations[i] = 'F'; }
			else if (note_y[i] > y1 + quarter_gap && note_y[i] <= y2 - quarter_gap) { solmizations[i] = 'E'; }
			else if (note_y[i] > y2 - quarter_gap && note_y[i] <= y2 + quarter_gap) { solmizations[i] = 'D'; }
			else if (note_y[i] > y2 + quarter_gap && note_y[i] <= y3 - quarter_gap) { solmizations[i] = 'C'; }
			else if (note_y[i] > y3 - quarter_gap && note_y[i] <= y3 + quarter_gap) { solmizations[i] = 'B'; }
			else if (note_y[i] > y3 + quarter_gap && note_y[i] <= y4 - quarter_gap) { solmizations[i] = 'A'; }
			else if (note_y[i] > y4 - quarter_gap && note_y[i] <= y4 + quarter_gap) { solmizations[i] = 'G'; }
			else if (note_y[i] > y4 + quarter_gap && note_y[i] <= y5 - quarter_gap) { solmizations[i] = 'F'; }
			else if (note_y[i] > y5 - quarter_gap && note_y[i] <= y5 + quarter_gap) { solmizations[i] = 'E'; }
			else if (note_y[i] > y5 + quarter_gap && note_y[i] <= y5 + gap - quarter_gap) { solmizations[i] = 'D'; }
			else if (note_y[i] > y5 + gap - quarter_gap && note_y[i] <= y5 + gap + quarter_gap) { solmizations[i] = 'C'; }
		}
        solmizations[this->sol_nums] = '\0';

		return solmizations;

	}
};

Image::Image(cv::Mat cv_image, image_color c) {
	this->cols = cv_image.cols;
	this->rows = cv_image.rows;
	this->type = c;

	this->pixels = new int** [3];

	for (int channel = 0; channel < 3; channel++) {
		this->pixels[channel] = new int* [rows];
		for (int row = 0; row < rows; row++) {
			this->pixels[channel][row] = new int[cols];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int channel = 0; channel < 3; channel++) {
				if (c == COLOR) {
					this->pixels[channel][i][j] = cv_image.at<cv::Vec3b>(i, j)[channel];
				}
				else if (c == GRAY) {
					
					if (channel == 0) {
						this->pixels[channel][i][j] = cv_image.at<uchar>(i, j);
					}
					else {
						this->pixels[channel][i][j] = 0;
					}
				}
			}
		}
		// std::cout << i << std::endl;
	}
	// std::cout << "y";
	

}

Image::Image(int x, int y, image_color c) {
	this->cols = x;
	this->rows = y;
	this->type = c;

	this->pixels = new int** [3];

	for (int channel = 0; channel < 3; channel++) {
		this->pixels[channel] = new int* [cols];
		for (int col = 0; col < cols; col++) {
			this->pixels[channel][col] = new int[rows];
		}
	}

}

// need to improve !!!!
void Image::resize(int re_x, int re_y) {
	float scale_x = (float)re_x / this->cols;
	float scale_y = (float)re_y / this->rows;

	int*** re_pixels;
	re_pixels = new int** [3];
	for (int channel = 0; channel < 3; channel++) {
		re_pixels[channel] = new int* [re_y];
		for (int i = 0; i < re_y; i++) {
			re_pixels[channel][i] = new int[re_x];
			// std::cout << int(i / scale_x) << std::endl;
			for (int j = 0; j < re_x; j++) {
				re_pixels[channel][i][j] = this->pixels[channel][(int)(i / scale_y)][(int)(j / scale_x)];
			}
			if(i< this->cols) delete[] this->pixels[channel][i];
		}
		delete[] this->pixels[channel];
	}
	delete[] this->pixels;
	this->pixels = re_pixels;
	this->cols = re_x;
	this->rows = re_y;
	
}

void Image::show(std::string name) {
	int x = this->cols;
	int y = this->rows;
	cv::Mat cv_image;
	
	if (this->type == COLOR) {
		cv_image = cv::Mat(cv::Size(x, y), CV_8UC3);
	}
	else {
		cv_image = cv::Mat(cv::Size(x, y), CV_8UC1);
	} 
	
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			for (int channel = 0; channel < 3; channel++) {
				if (this->type == COLOR) {
					cv_image.at<cv::Vec3b>(i,j)[channel] = this->pixels[channel][i][j];
				}
				else if (this->type == GRAY) {
					if (channel == 0) {
						cv_image.at<uchar>(i, j) = this->pixels[channel][i][j];
					}
					else {
						break;
					}
				}
			}
		}
	}
	cv::imshow(name, cv_image);
}

Image::~Image() { ; }
