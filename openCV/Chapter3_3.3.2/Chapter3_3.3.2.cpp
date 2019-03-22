#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void print_vectorInfo(String v_name, vector<int> v) { //벡터 정보출력, 이름, 크기,원소 값

	cout << "[" << v_name << "] = " << endl;
	if (v.empty()) cout << "벡터가 비었습니다." << endl;
	else {
		cout << (Mat)v << endl<<endl;
		cout << ((Mat)v).reshape(1, 1) << endl;
	}
		

	cout << ".size() = " << v.size() << endl; 
}

int main() {

	//vector클래스 사용 
	//벡터 원소 접근 - 배열 처럼 첨자연산자([])이용
	//벡터 할당된 용량 확인 vector::capacity()
	//벡터 메모리 확보 vector::reserve()

	int arr[] = { 10,20,30,40,50 };							//벡터 초기화할 배열
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));	//배열로 벡터 초기화 

	print_vectorInfo("v1", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;

	cout << endl; 
	v1.insert(v1.begin() + 2, 100);							//인덱스 2번 위치에 100을 삽입
	print_vectorInfo("v1의 2번 인덱스에 100삽입 ", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl; //size와 capacity의 값이 다르게 나온다.
															   //둘의 차이는 C++ Additional Method of Programming Chap7 에서확인
	//전체 원소개수는 하나 증가하여 6 원소삽입 시 벡터 공간이 부족하여 증가할 때는 재할당이 발생하며, 메모리가 2개씩 증가
	//따라서 v1벡터의 할당메모리(capacity)는 7이됨 

	v1.erase(v1.begin() + 3);
	print_vectorInfo("v1의 3번 인덱스를 삭제", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;

	v1.clear();
	print_vectorInfo("v1의 원소 목두 삭제", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;
	

	


	
	return 0;

}