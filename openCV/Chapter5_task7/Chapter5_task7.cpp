#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


//컬러영상 파일을 입력받아 RGB 3개 채널로 분리, 각 채널을 컬러 영상으로 윈도우 표시하자.
//Red 채널 -> Red, Green 채널 -> Green, Blue 채널 -> Blue 로 표현 

//단일 채널 행렬을 imshow()로 출력하면 명암도 영상이 출력, 컬러 영상을 출력하면 3개 채널이 합성된 행렬이야함.
//컬러 영상을 분리하고 분리된 단일 채널 행렬들을 어떻게 하면 해당 정보를 표현하는 컬러 영상으로 합성할지? 

//merge(), split(), vector를 이용하자 

int main() {
	
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/opencvLogo.png",1);		//경로, 컬러타입 상수 p.168 imread()
	Mat bgr[3];
	Mat blue_img, green_img, red_img;
	Mat zero(image.size(), CV_8U, Scalar(0));

	split(image,bgr);
															
	imshow("original image", image);			//원본이미지
	imshow("Blue_image", bgr[0]);				//B 채널 	
	imshow("Green image", bgr[1]);				//G 채널
	imshow("Red image", bgr[2]);				//R 채널
	imshow("black zero", zero);					//검은색 바탕 

	vector<Mat> vecB, vecG, vecR;

	vecB.push_back(bgr[0]);						//3채널로 B속성만 
	vecB.push_back(zero);		
	vecB.push_back(zero);

	vecG.push_back(zero);		
	vecG.push_back(bgr[1]);						//3채널로 G채널만	
	vecG.push_back(zero);

	vecR.push_back(zero);
	vecR.push_back(zero);
	vecR.push_back(bgr[2]);						//3채널로 R채널만 	

	Mat B, G, R;

	merge(vecB,B);								//vector 합치기 	
	merge(vecG,G);
	merge(vecR,R);

	imshow("Only Blue",		B);
	imshow("Only Green",	G);
	imshow("Only Red",		R);

	waitKey();
	return 0;
}


