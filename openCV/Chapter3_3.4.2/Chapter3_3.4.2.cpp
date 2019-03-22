#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void print_locateROI(String str, Mat m) {	  //부분 행렬의 헤더 정보 콘솔창 출력
											  //부모크기, 시작위치, 부분행렬 크기 	
	Size size;
	Point pt; 

	//locateROT(Size& wholeSize(부모행렬크기), Point& ofs(부모행렬에서 부분행렬의 위치))
	m.locateROI(size, pt);					  //부분 행렬의 크기와 시작좌표를 가지고온다

	cout << "부모 크기" << size << ",";
	cout << "부분 행렬크기 " << "[" << str << "] = " <<  m.size() << "from" << pt << endl;
}

int main() {

	//Range 클래스 
	//원본 행렬을 참조하여 부분행렬을 만들고 부분행렬의 참조의 범위를 확인하며 그범위를 조정하는 방법 
	
	Range r1(0, 3), r2(3, 7); 
	int data[] = {				
	10,11,12,13,14,15,16,
	20,21,22,23,24,25,26,
	30,31,32,33,34,35,36,
	40,41,42,43,44,45,46,
	50,51,52,53,54,55,56,
	};
	
	Mat m1(5, 7, CV_32S, data);
	Mat m2 = m1(r1, r2);				//(3,0)에서 시작하여 3행 4열짜리 행렬 //0~2행 3~6열 관심 영역 참조 
	Mat m3 = m1(r1, r1);				//(0,0)에서 시작하여 3행 3열짜리 행렬 //0~2행,0~2열 관심 영역 참조 

	print_locateROI("m1", m1);
	print_locateROI("m2", m2);
	print_locateROI("m3", m3);

	cout << endl; 
	cout << "m1 행렬" << endl << m1 << endl << endl;
	cout << "m2 행렬" << endl << m2 << endl << endl;
	cout << "m3 행렬" << endl << m3 << endl << endl;

	m2.adjustROI(-1, 1, 2, -1);			//관심 영역 변경, 지정된 영역을 옮기는 것이 아니라 4방향으로 각각 늘리거나 줄인다고 생각 
	m3.adjustROI(0, -1, -2, 2);

	cout << endl << "관심영역 변경 후" << endl; 
	print_locateROI("m1", m1);
	print_locateROI("m2", m2);
	print_locateROI("m3", m3);
	cout << endl; 

	cout << "m1 행렬" << endl << m1 << endl << endl;
	cout << "변경된 m2 행렬" << endl << m2 << endl << endl;
	cout << "변경된 m3 행렬" << endl << m3 << endl << endl;
	return 0;

}