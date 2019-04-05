#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.4.3 행렬 최솟값 최댓값 연산 

//히스토그램에서 min,max를 추출해서 영상의 적정밝기로 보정가능 
int main(){

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/dark.jpg", IMREAD_GRAYSCALE);
	
	
	double minVal, maxVal;
	minMaxIdx(image, &minVal, &maxVal);														//이미지의 최소값, 최대값 가지고 오기 


	double ratio = (maxVal - minVal) / 255.0;
	Mat dst = (image - minVal) / ratio;

	cout << "최솟값 = " << minVal << endl; 
	cout << "최댓값 = " << maxVal << endl;

	//resize(image, dst, Size(900, 700), 0, 0, IMREAD_GRAYSCALE);	//이미지 크기 변경 
	imshow("image", image);
	imshow("dst", dst);
	waitKey();
	return 0;


}

