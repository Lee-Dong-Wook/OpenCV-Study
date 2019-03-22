#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//Mat 클래스의 다양한 속성 p.92 확인 
	//4 = row(행), 3 = col(열) 
	//CV_32F = 행렬의 깊이(행렬의 자료형)의 매핑 값, C3 = 채널
	//type = 행렬의 데이터 타입(자료형 + 채널 수)반환 자료형으로 상위 3비트 + 채널 수로 하위 3비트 

	Mat m1(5, 3, CV_32FC3);
	cout << " 차원 수 = " <<m1.dims << endl;		//2
	cout << " 행 개수 = " <<m1.rows << endl;		//5    
	cout << " 열 개수 = " <<m1.cols << endl;		//3
	cout << " 행렬 크기 = " << m1.size() << endl << endl;				  // 3x5=15

	cout << " 전체 원소 개수 =  " <<m1.total() << endl;					  // 3x5 = 15 
	cout << " 한 원소의 크기 =  " <<m1.elemSize() << endl;				 // 채널 3개 중 각 4byte 씩 3개, float32bit = 4byte x 3 = 12byte 
	cout << " 채널당 한 원소의 크기 =  " <<m1.elemSize1() << endl << endl;//float형 32bit 채널 1개 = 4byte 

	cout << " 채널 =  " << m1.channels() << endl;		//3 
	cout << " 깊이 =  " << m1.depth() << endl;			//매핑값 5 
	cout << " 타입 =  " <<m1.type() << endl;
	cout << " 타입(채널 수 깊이) =  " <<((m1.channels() -1) << 3) + m1.depth() << endl; // 3 -1 = 2 = 2진수10 , 10을 왼쪽으로 3
																					   // 1000 = 16, 16+5 = 21
	
	cout << " step =  " << m1.step << endl;			//행렬의 한 행이 차지하는 바이트 수 12byte x 3열 =  36 
	cout << " step1() = " << m1.step1() << endl;	//

	return 0;
}