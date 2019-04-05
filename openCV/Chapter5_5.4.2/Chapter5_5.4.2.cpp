#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.4.2 행렬 최솟값 및 최댓값 연산 1

//두 행렬의 각 원소를 비교, 큰 값이나 작은 값들을 모아 찾는다. 
//하나의 행렬 내에서 큰 값이나 가장 작은 값의 위치를 알면 히스토그램 그래프 그리기나 다른 행렬연산 등에서 유용 
//src1와 src2를 비교해서 둘중에 크거나 작은 값을 해당 원소에 적용 

//cv::max(), cv::min(), cv::minLoc()

int main() {

	uchar data[] = {

		10,200,5,7,9,
		15,35,60,80,170,
		100,2,5,37,70
	};

	Mat m1(3,5,CV_8U,data);
	Mat m2(3,5,CV_8U,Scalar(50));
	Mat m_min, m_max;					//최소, 최대값 행렬 
	
	double minVal, maxVal;
	int minIdx[2] = {}, maxIdx[2] = {};	//최솟값 좌표, 최댓값 좌표 
	
	Point minLoc, maxLoc; 
										
	min(m1, 30, m_min);					//두 행렬 원소 간 최솟값 저장 
	max(m1, m2, m_max);					//두행렬 최댓값 계산 
	
	minMaxIdx(m1, &minVal, &maxVal, minIdx, maxIdx); //m1의 최솟값, 최댓값, 최솟값 위치, 최댓값 위치
	minMaxLoc(m1, 0, 0, &minLoc, &maxLoc);			//m1의 최솟값, 최댓값, 최솟값 위치, 최댓값 위치 , Point 객체로 받음	

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m_min] = " << endl << m_min << endl << endl;
	cout << "[m_max] = " << endl << m_max << endl << endl;

	cout << "m1 행렬 원소 최솟값 :  " << endl << minVal << endl << endl;
	cout << "최솟값 좌표 : " << endl << minIdx[1] << " , " << minIdx[0] << endl << endl;

	cout << "m1 행렬 원소 최댓값 : " << endl << maxVal  << endl << endl;
	cout << "최댓값 좌표 : " << endl << maxIdx [1] << " , " << maxIdx[0] << endl << endl;

	cout << "m1 최솟값 좌표 :  " << endl << minLoc << endl << endl;
	cout << "m1 최댓값 좌표 : " << endl << maxLoc << endl << endl;
	return 0;
}

