#include <opencv2/highgui.hpp>
#include <time.h>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//vector Ŭ���� �޸� �Ҵ� 
	//������ ���Ҵ����� ���� �ӵ� ���� �ľ� 
	//reverse()�� ����� �Ͱ� ���� ���� ���� ���̸� �ľ� 
	
	vector<double> v1, v2;
	v1.reserve(100000);							//���� �޸� �Ҵ� 

	double start_time = clock();				//���� ���� ���� �ð� üũ 

	for (int i = 0; i < v1.capacity(); i++) {
		
		v1.push_back(i);						//v1 ���� ���� ���� 
	}

	printf("reserve() ��� %5.2f ms \n ", (clock() - start_time));
	
	start_time = clock();						//���� ���� ���� �ð� üũ 

	for (int i = 0; i < v1.capacity(); i++) {
		
		v2.push_back(i);						//v2 ���� ���� ���� 		
	}

	printf("reserve() ��� %5.2f ms \n ", (clock() - start_time));

	return 0;
}