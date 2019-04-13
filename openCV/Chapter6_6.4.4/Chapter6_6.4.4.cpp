#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.4 다양한 컬러 공간 변환 

int main() {

	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Mat YCC_img, YUV_img, Lab_img, Gray_img;				

	cvtColor(BGR_img, Gray_img, COLOR_BGR2GRAY);		//명암도 
	cvtColor(BGR_img, YCC_img,  COLOR_BGR2YCrCb);		//YCbCr
	cvtColor(BGR_img, YUV_img,  COLOR_BGR2YUV);			//YUV
	cvtColor(BGR_img, Lab_img,  COLOR_BGR2Lab);			//La*b*

	Mat YCC_arr[3], YUV_arr[3], Lab_arr[3];

	split(YCC_img, YCC_arr);
	split(YUV_img, YUV_arr);
	split(Lab_img, Lab_arr);


	imshow("BGR_img", BGR_img);
	imshow("Gray_img", Gray_img);
	imshow("YCC_arr Y", YCC_arr[0]);
	imshow("YCC_arr Cr", YCC_arr[1]);
	imshow("YCC_arr Cb", YCC_arr[2]);
	imshow("YUV_arr Y", YUV_arr[0]);
	imshow("YUV_arr U", YUV_arr[1]);
	imshow("YUV_arr V", YUV_arr[2]);
	imshow("Lab_arr L", Lab_arr[0]);
	imshow("Lab_arr a", Lab_arr[1]);
	imshow("Lab_arr b", Lab_arr[2]);
	
	waitKey();
	return 0;
}