#include <opencv2/highgui.hpp>
#include <time.h>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//vector 클래스 메모리 할당 
	//벡터의 재할당으로 인한 속도 저하 파악 
	//reverse()를 사용한 것과 하지 않은 것의 차이를 파악 
	
	vector<double> v1, v2;
	v1.reserve(100000);							//벡터 메모리 할당 

	double start_time = clock();				//벡터 원소 삽입 시간 체크 

	for (int i = 0; i < v1.capacity(); i++) {
		
		v1.push_back(i);						//v1 벡터 원소 삽입 
	}

	printf("reserve() 사용 %5.2f ms \n ", (clock() - start_time));
	
	start_time = clock();						//벡터 원소 삽입 시간 체크 

	for (int i = 0; i < v1.capacity(); i++) {
		
		v2.push_back(i);						//v2 벡터 원소 삽입 		
	}

	printf("reserve() 사용 %5.2f ms \n ", (clock() - start_time));

	return 0;
}