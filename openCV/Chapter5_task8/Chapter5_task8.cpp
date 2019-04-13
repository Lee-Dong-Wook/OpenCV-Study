#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

//특정 영역의 타원만을 복사하여 새 창에 표시한다. 

//마스크 행렬 이용
//다른 함수를 사용해서 같은 결과(dst1, dst2, dst3)가 나도록 구성 (예 : bitwise_and(), bitwise()_or() 등)
//타원 영역의 중심과 크기는 임의로 지정한다(예 : 120, 120)

//bitwise..(입력 배열 혹은 스칼라, 입력배열 혹은 스칼라, 입력배열과 같은 크기의 출력배열, 마스크 연산(8비트단일채널) - 마스크의 원소가 0이 아닌 좌표만 계산  )

//지정한 타원부분은 원래 이미지로 남기고, 그 외 부분을 검은색으로 

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/heeju.jpg",IMREAD_COLOR);
	CV_Assert(image.data);

	Mat imageResize;
	cv::resize(image, imageResize, cv::Size(400,400), 0, 0, INTER_LINEAR);

	//dst3초기화하는 이유 
	//초기화를 해주지 않으면 0으로 초기화 될 수도 205로 초기화 될 수있다. 
	//이를 방지하기 위해서 초기화 시키는 것임. 

		//마스크 행렬의 원소가 0이 아닌 위치만 복사
		//masks행렬의 전경이 255이기 때문에 로고의 전경 부분만 dst 행렬에 복사 


	Mat dst1;
	Mat dst2;
	Mat dst3(imageResize.size(), CV_8UC3, Scalar(0, 0, 0));

	Mat mask(imageResize.size(), CV_8U, Scalar(0));
	Mat black(imageResize.size(), CV_8UC3, Scalar(0));

	imshow("Raw_leehee", imageResize);

	imshow("black", black);

	Point center(150, 150);
	ellipse(mask, center, Size(100,100), 0, 0, 360, Scalar(255), -1);
	imshow("mask", mask);
	
	bitwise_and(imageResize, imageResize,dst1,mask);

	bitwise_or(imageResize,black,dst2,mask);
	
	bitwise_xor(imageResize, black , dst3, mask);
	
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	waitKey();
	return 0;
}


