#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void print_locateROI(String str, Mat m) {	  //�κ� ����� ��� ���� �ܼ�â ���
											  //�θ�ũ��, ������ġ, �κ���� ũ�� 	
	Size size;
	Point pt; 

	//locateROT(Size& wholeSize(�θ����ũ��), Point& ofs(�θ���Ŀ��� �κ������ ��ġ))
	m.locateROI(size, pt);					  //�κ� ����� ũ��� ������ǥ�� ������´�

	cout << "�θ� ũ��" << size << ",";
	cout << "�κ� ���ũ�� " << "[" << str << "] = " <<  m.size() << "from" << pt << endl;
}

int main() {

	//Range Ŭ���� 
	//���� ����� �����Ͽ� �κ������ ����� �κ������ ������ ������ Ȯ���ϸ� �׹����� �����ϴ� ��� 
	
	Range r1(0, 3), r2(3, 7); 
	int data[] = {				
	10,11,12,13,14,15,16,
	20,21,22,23,24,25,26,
	30,31,32,33,34,35,36,
	40,41,42,43,44,45,46,
	50,51,52,53,54,55,56,
	};
	
	Mat m1(5, 7, CV_32S, data);
	Mat m2 = m1(r1, r2);				//(3,0)���� �����Ͽ� 3�� 4��¥�� ��� //0~2�� 3~6�� ���� ���� ���� 
	Mat m3 = m1(r1, r1);				//(0,0)���� �����Ͽ� 3�� 3��¥�� ��� //0~2��,0~2�� ���� ���� ���� 

	print_locateROI("m1", m1);
	print_locateROI("m2", m2);
	print_locateROI("m3", m3);

	cout << endl; 
	cout << "m1 ���" << endl << m1 << endl << endl;
	cout << "m2 ���" << endl << m2 << endl << endl;
	cout << "m3 ���" << endl << m3 << endl << endl;

	m2.adjustROI(-1, 1, 2, -1);			//���� ���� ����, ������ ������ �ű�� ���� �ƴ϶� 4�������� ���� �ø��ų� ���δٰ� ���� 
	m3.adjustROI(0, -1, -2, 2);

	cout << endl << "���ɿ��� ���� ��" << endl; 
	print_locateROI("m1", m1);
	print_locateROI("m2", m2);
	print_locateROI("m3", m3);
	cout << endl; 

	cout << "m1 ���" << endl << m1 << endl << endl;
	cout << "����� m2 ���" << endl << m2 << endl << endl;
	cout << "����� m3 ���" << endl << m3 << endl << endl;
	return 0;

}