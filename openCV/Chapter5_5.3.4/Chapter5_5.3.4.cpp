#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.4 행렬 비트 연산 
//과제 8번에 써먹으면 되겠다. 

//0은 balck , black 이외의 모든 색상은 1 
//0 = false, 1 = true 


int main() {

	Mat image1(300, 300, CV_8U, Scalar(0));				//300행 x 300열 검은색 영상 생성
	Mat image2(300, 300, CV_8U, Scalar(0));				//300행 x 300열 검은색 영상 생성
	Mat image3, image4, image5, image6;
	
	imshow("pre_image1", image1);						
	imshow("Pre_image2", image2);						

	Point center = image1.size() / 2;									//영상 중심좌표 계산 
	circle(image1, center, 100, Scalar(255,0,0),-1);						//image1에 대해 중심으로 부터 100의 반지름으로 흰색으로 -1두께로 원그리기 
	rectangle(image2, Point(0, 0), Point(150, 300), Scalar(255), -1);   //image2에 대해 0,0시작, 150,300끝지점 으로 사각형을 만들어
																		//-1 두께로 흰색으로 사각형 생성 							

	imshow("circle_image1", image1);
	imshow("rect_image2", image2);

	//비트 연산 (입력, 입력, 출력 )
	bitwise_or (image1, image2, image3);								//circle_image1과 rect_image2를 비트연산 or -> 비교하여 true면 흰색으로 
	bitwise_and(image1, image2, image4);								//circle_image1과 rect_image2를 비트연산 and -> 비교해서 true면 흰색으로 
	bitwise_xor(image1, image2, image5);								//circle_image1과 rect_image2를 비트연산 xor 
	bitwise_not(image1, image6);										//circle_image1을 반전 	

	imshow("image1",	  image1);
	imshow("image2",      image2);
	imshow("bitwise_or",  image3);
	imshow("bitwise_and", image4);
	imshow("bitwise_xor", image5);
	imshow("bitwise_not", image6);

	waitKey();
	return 0;
}

