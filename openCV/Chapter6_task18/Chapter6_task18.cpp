#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//컬러영상을 입력 받아 YCbCr컬러 공간으로 변환하고 다시 환원하는 프로그램 작성 

Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);


void bgr2Ycbcr(Mat img, Mat &ycbcr);

void Ycbcr2Bgr(Mat img, Mat &bgr);

int main() {

	CV_Assert(image.data);

	Mat openCV_bgr2ycbcr,		//openCV - BGR -> YCbCr
		bgr_img,				//openCV - YCbCr -> BGR
		bgr2ycbcr,				//		   BGR -> YCbCr
		ycbcr2bgr;				//		   YCbCr -> BGR
		

	imshow("Original_BGR_image", image);
	
	cvtColor(image, openCV_bgr2ycbcr, COLOR_BGR2YCrCb);
	imshow("OpenCV_BGR -> YCbCr", openCV_bgr2ycbcr);

	cvtColor(openCV_bgr2ycbcr, bgr_img, COLOR_YCrCb2BGR);
	imshow("OpenCV_YCbCr -> BGR", bgr_img);


	bgr2Ycbcr(image, bgr2ycbcr);
	imshow("BGR -> YCbCr", bgr2ycbcr);

	Ycbcr2Bgr(bgr2ycbcr, ycbcr2bgr);
	imshow("YCbCr -> BGR", ycbcr2bgr);

	
	waitKey(0);
	return 0;
}


void bgr2Ycbcr(Mat img, Mat &ycbcr) {					//이미지 각 픽셀은 1byte BGR, 3채널 컬러 영상이다. CV_8UC3
														//ycbcr 행렬은 계산되는 변수들이 float형이기 때문에 3채널 float형으로 선언한다. 
	ycbcr = Mat(img.size(), CV_32FC3);

	for (int i = 0; i < img.rows; i++) {				//이미지 전체 순회 
		for (int j = 0; j < img.cols; j++) {

			float B		= img.at<Vec3b>(i, j)[0];			//BGR 순서로 요소가 들어가기 때문에 BGR순으로 벡터에 삽입
			float G		= img.at<Vec3b>(i, j)[1];
			float R		= img.at<Vec3b>(i, j)[2];

			float Y		= 0.299f * R + 0.587f * G + 0.114f * B;		//휘도
			float Cb	= (R - Y) * 0.564f + 128;					//색차정보 
			float Cr	= (B - Y) * 0.713f + 128;

			ycbcr.at<Vec3f>(i, j) = Vec3f(Y, Cb, Cr);	//float형 Y, Cb, Cr 또한 vector를 통해 행렬에 삽입 
		}
	}
	ycbcr.convertTo(ycbcr, CV_8UC3);					//출력은 이미지 형태로 하기 때문에 float형을 byte형으로 변환한다. 
}


void Ycbcr2Bgr(Mat img, Mat &bgr) {
														
	bgr = Mat(img.size(), CV_32FC3);

	for (int i = 0; i < img.rows; i++) {				//이미지 전체 순회 
		for (int j = 0; j < img.cols; j++) {

			float Y		= img.at<Vec3b>(i, j)[0];			
			float Cb	= img.at<Vec3b>(i, j)[1];			//Cb, Cr은 순서 상관이 심하다. 
			float Cr	= img.at<Vec3b>(i, j)[2];
		
			float R		= Y + 1.403f*(Cr - 128);
			float G		= Y - 0.714f*(Cb - 128) - 0.344f*(Cb - 128);
			float B		= Y + 1.7773f*(Cb - 128);
			
			

			bgr.at<Vec3f>(i, j) = Vec3f(R, G, B);	//float형 Y, Cb, Cr 또한 vector를 통해 행렬에 삽입 
		}
	}
	bgr.convertTo(bgr, CV_8UC3);					//출력은 이미지 형태로 하기 때문에 float형을 byte형으로 변환한다. 
}
