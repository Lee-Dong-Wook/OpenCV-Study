#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.2.2 컬러 채널 분리 
//원본영상을 각각 Blue, Green, Red에 대해서 추출한다. 
//단일 채널 영상이기 때문에 윈도우에 명암도 영상으로 나타낸다. 


int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/image1.jpg",IMREAD_COLOR);	//컬러 영상 로드 
	CV_Assert(image.data);																	//예외 처리 

	Mat bgr[3];
	split(image, bgr);																		//3채널 행렬을 3개 원소를 갖는 행렬 배열로 분리 
	

	imshow("image",image);
	imshow("Blue bgr[0]",bgr[0]);
	imshow("Green bgr[1]",bgr[1]);
	imshow("Red bgr[2]",bgr[2]);
	
	waitKey();
	return 0;
}

