#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main() {

	//vector Ŭ���� �ʱ�ȭ 
	vector<Point> v1;					//Point ��ü�� ���ҷ� ���� ���� ���� 

	v1.push_back(Point(10, 20));
	v1.push_back(Point(20, 30));
	v1.push_back(Point(50, 60));

	vector<float> v2(3, 9.25);			//float �� ���Ҹ� ���� ���� ����, 3���� ���Ҹ� 9.25�� �ʱ�ȭ
	Size arr_size[] = { Size(2,2),Size(3,3),Size(4,4)};  
	int  arr_int[] = { 10,20,30,40,50 };

	//�迭���ҷ� ���� �ʱ�ȭ 
	vector<Size> v3(arr_size, arr_size + sizeof(arr_size) / sizeof(Size));	//sizeof(arr_size) = �迭���� , Size�� ���� ����  
	vector<int>  v4(arr_int + 2, arr_int + sizeof(arr_int) / sizeof(int));	//int�� ���� ���� 

	cout << "[v1]" << endl << (Mat)v1 << endl << endl;
	cout << "[v2]" << endl << ((Mat)v2) << endl << endl;
	cout << "[v2]" << endl << ((Mat)v2).reshape(1, 1) << endl << endl;
	cout << "[v3]" << endl << ((Mat)v3) << endl << endl;
	cout << "[v3]" << endl << ((Mat)v3).reshape(1, 1) << endl << endl;
	cout << "[v4]" << endl << ((Mat)v4) << endl << endl;
	cout << "[v4]" << endl << ((Mat)v4).reshape(1, 1) << endl << endl;
	return 0;

}