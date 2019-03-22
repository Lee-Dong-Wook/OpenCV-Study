#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main() {

	//vector 클래스 초기화 
	vector<Point> v1;					//Point 객체를 원소로 갖는 벡터 선언 

	v1.push_back(Point(10, 20));
	v1.push_back(Point(20, 30));
	v1.push_back(Point(50, 60));

	vector<float> v2(3, 9.25);			//float 형 원소를 갖는 벡터 선언, 3개의 원소를 9.25로 초기화
	Size arr_size[] = { Size(2,2),Size(3,3),Size(4,4)};  
	int  arr_int[] = { 10,20,30,40,50 };

	//배열원소로 벡터 초기화 
	vector<Size> v3(arr_size, arr_size + sizeof(arr_size) / sizeof(Size));	//sizeof(arr_size) = 배열개수 , Size형 벡터 선언  
	vector<int>  v4(arr_int + 2, arr_int + sizeof(arr_int) / sizeof(int));	//int형 벡터 선언 

	cout << "[v1]" << endl << (Mat)v1 << endl << endl;
	cout << "[v2]" << endl << ((Mat)v2) << endl << endl;
	cout << "[v2]" << endl << ((Mat)v2).reshape(1, 1) << endl << endl;
	cout << "[v3]" << endl << ((Mat)v3) << endl << endl;
	cout << "[v3]" << endl << ((Mat)v3).reshape(1, 1) << endl << endl;
	cout << "[v4]" << endl << ((Mat)v4) << endl << endl;
	cout << "[v4]" << endl << ((Mat)v4).reshape(1, 1) << endl << endl;
	return 0;

}