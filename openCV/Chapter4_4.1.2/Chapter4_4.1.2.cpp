#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	//4.1.2 윈도우 크기 변경 
	
	Mat image(300, 400, CV_8U, Scalar(255));			//흰색 바탕 영상 생성, 1채널 uchar 행렬, 255로 초기화  
	string title1 = "창 크기 변경 1 - AUTOSIZE";			//윈도우 이름 
	string title2 = "창 크기 변경 2 - NORMAL";			

	namedWindow(title1, WINDOW_AUTOSIZE);				//윈도우 크기 변경 불가, 창 이름 지정 
	namedWindow(title2, WINDOW_NORMAL);					//윈도우 크기 변경 가능 
	
	resizeWindow(title1, 500, 200);						 
	resizeWindow(title2, 500, 200);						//창 크기 변경	

	imshow(title1, image);								//title1 창에 image 행렬을 영상으로 표시 
	imshow(title2, image);
	waitKey();

	return 0;
}

