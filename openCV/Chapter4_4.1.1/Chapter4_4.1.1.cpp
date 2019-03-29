#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	//4.1.1 윈도우(영상 출력창) 이동
	
	Mat image1(300, 400, CV_8U, Scalar(255));			//흰색바탕 영상 생성
	Mat image2(300, 400, CV_8U, Scalar(100));			//회색바탕 영상 생성
	string title1 = "white창 제어";						//원도우 이름 
	string title2 = "gray 창 제어";

	namedWindow(title1, WINDOW_AUTOSIZE);				//윈도우 이름 지정, cv::imshow()함수에 입력되는 
														//행렬의 크기에 맞춰 생성,창크기 변경불가
	namedWindow(title2, WINDOW_NORMAL);					//창 크기가 임의로 생성, 사용 자가 마우스로 창의 크기 변경 가능
	moveWindow(title1, 100, 200);						//윈도우 이동(모니터의 위치로) 
	moveWindow(title2, 300, 200);

	imshow(title1, image1);								//행렬 원소를 영상으로 표시 
	imshow(title2, image2);
	waitKey();											//키 이벤트 대기 
	destroyAllWindows();								//열린 모든 윈도우 제거 
	
	return 0;
}

