#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.5 hue 채널을 이용한 객체 검출 

//입력 영상을 HSV컬러 공간으로 변환한 후 Hue 채널을 이용해 특정 색상 범위를 지정
//이 범위의 색상만 선택적으로 이진화하는 예제 

Range th(50, 100);								//트랙바로 선택할 범위 변수 default 값
Mat	  hue;										//색상 채널 전역변수 지정 

void onThreshold(int value, void* userdata) {

	Mat result = Mat(hue.size(), CV_8U, Scalar(0));

	//선택 범위에 이진화 수행 
	for (int i = 0; i < result.rows; i++) {
		for (int j = 0; j < result.cols; j++) {	//선택범위에 대한 조건 설정 

			bool ck =  hue.at<uchar>(i, j) >= th.start && hue.at<uchar>(i, j) < th.end;     //행렬의 각 화소가 범위 시작 값보다 크고, 범위 종료값보다 작으면 참
			result.at<uchar>(i, j) = (ck) ? 255 : 0;										//result 행렬 원소에 ck가 참이면 흰색255, 거짓이면 0지정 
																													
		}
	}

	imshow("result",result);
}

int main() {
   
	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg", 1);			
	CV_Assert(BGR_img.data);

	Mat HSV, hsv[3];
	cvtColor(BGR_img, HSV, COLOR_BGR2HSV);					//컬러 공간 변환 
	split(HSV,hsv);											//채널 분리 
	hsv[0].copyTo(hue);										//hue 행렬에 색상 채널 복사 

	namedWindow("result", WINDOW_AUTOSIZE);

	createTrackbar("Hue_th1","result", &th.start,255, onThreshold);
	createTrackbar("Hue_th2", "result", &th.end, 255, onThreshold);

	//onThreshold();

	imshow("BGR_img", BGR_img);
	waitKey(0);
	waitKey();
	return 0;
}