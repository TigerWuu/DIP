#include "IP.h"
#include <QDebug>


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
		//int height = histdata[0];
		int height = 1000;
		/*for (int i = 0; i < bin; i++) {
			if (histdata[i] > height) {
				height = histdata[i];
			}
		}*/
		cv::Mat histimage = cv::Mat(cv::Size(bin * binscale, height), CV_8UC1);

		for (int i = 0; i < bin; i++) {
			for (int j = 0; j < binscale; j++) {
				cv::Point p1(i * binscale + j, height);
				cv::Point p2(i * binscale + j, height - histdata[i]);
				cv::line(histimage, p1, p2, 64);
			}
		}

		delete[] histdata;

		return histimage;
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

    cv::Mat pseudocolor(cv::Mat srcimage,float phase_shift) {
		int x = srcimage.cols;
		int y = srcimage.rows;
		float pi = 3.1415;
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
        float pi = 3.1415;
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

}

Image::Image(cv::Mat cv_image, image_color c) {
	this->cols = cv_image.cols;
	this->rows = cv_image.rows;
	this->type = c;

	this->pixels = new int** [3];

	for (int channel = 0; channel < 3; channel++) {
		this->pixels[channel] = new int* [cols];
		for (int col = 0; col < cols; col++) {
			this->pixels[channel][col] = new int[rows];
		}
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
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
	}
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
Image Image::resize(int re_x, int re_y) {
	float scale_x = (float)re_x / this->cols;
	float scale_y = (float)re_y / this->rows;

	Image re_image(re_x, re_y, this->type);

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			for (int channel = 0; channel < 3; channel++) {
				re_image.pixels[channel][i][j] = this->pixels[channel][(int)(i / scale_x)][(int)(j / scale_y)];
			}
		}
	}
	return re_image;
}
Image::~Image() { ; }
