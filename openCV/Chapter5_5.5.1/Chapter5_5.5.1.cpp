#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.1 행렬 합 평균 연산 

//Scalar sum()		배열의 각 채널 별로 원소들의 합 N을 계산하여 스칼라 값으로 반환 
//Scalar mean()		배열의 각 채널 별로 원소들의 평균을 계산하여 스칼라값으로 반환 
//void meanStdDev() 배열원소들의 평균과 표준편차를 계산 
//int countNonZero() 0이아닌 배열 원소를 개수 N을 반환
//void reduce()		행렬을 열 혹은 행방향으로 옵션 상수(rtype)의 연산을 수행하여 벡터로 감축
//void sort()		행렬의 각 행, 열 방향으로 정렬 

//실행 결과 
//[sum_value] = [5.24488e+07, 5.24488e+07, 5.24488e+07, 0]		//원소들의 모든 합 
//
//[mean_value1] = [64.7516, 64.7516, 64.7516, 0]				//전체 영역 평균, 3개의 원소만 반환 마지막 원소는 0 
//
//[mean_value2] = [81.1467, 81.1467, 81.1467, 0]				//관심 영역 평균, 3개의 원소만 반환 마지막 원소는 0 
//
//[mean] = [64.75155925925927;									//전체 영역 평균/표준편차 						
//			64.75155925925927;
//			64.75155925925927]

//[stddev] = [49.30256737775272;								
//			  49.30256737775272;
//			  49.30256737775272]
//
//[mean] = [81.14673469387755;									//관심 영역 영역 평균/표준편차
//			81.14673469387755;
//			81.14673469387755]

//[stddev] = [6.529079344967299;
//			  6.529079344967299;
//			  6.529079344967299]

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg", 1); // 1은 컬러 모드 상수 값, 컬러 영상 로드 
	CV_Assert(image.data);
	
	Mat mask(image.size(), CV_8U, Scalar(0)), Mean, stddev; 
	
	mask(Rect(20, 40, 70, 70)).setTo(255);				//마스킹 영역 지정 - 해당 영역 계산 

	Scalar sum_value = sum(image);						//채널 원소간 합 
														//입력 행렬의 채널 수와 같은 개수의 원소를 반환
														//image 행렬이 3채널 영상이기 때문에 3개 원소가 반환되고 마지막원소는 0		
	
	Scalar mean_value1 = mean(image);					//평균계산 
	Scalar mean_value2 = mean(image, mask);				//평균계산, 마스크 원소 1인 영역만 계산 

	cout << "[sum_value] = " << sum_value << endl<<endl; 
	cout << "[mean_value1] = " << mean_value1 << endl<<endl; 
	cout << "[mean_value2] = " << mean_value2 << endl<<endl;

	meanStdDev(image, Mean, stddev);					//평균과 표준 편차 결과 저장 
														//Mean = 평균, stddev = 표준편차 			

	cout << "[mean] = " << Mean << endl;
	cout << "[stddev] = " << stddev << endl << endl;

	meanStdDev(image, Mean, stddev, mask);				//마스크 원소중 1인 위치만 image 행렬 평균/표준편차 계산
														//반환 행렬은 입력 행렬의 채널 수 x 1, image행렬의 채널 수가 3이라
														//3행, 1열 행렬이 출력 						
	cout << "[mean] = " << Mean << endl; 
	cout << "[stddev] = " << stddev << endl << endl;

	imshow("image", image);
	imshow("mask", mask);
	
	waitKey();

	return 0;
}

