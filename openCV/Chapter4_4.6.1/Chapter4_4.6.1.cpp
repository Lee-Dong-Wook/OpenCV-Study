#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.6.1 FileStorageŬ������ ������ ���� 
//openCV������ Mat,Rect,Point,Size ���� �پ��� �ڷᱸ���� XML�̳� YAML ������ ���Ϸ� ����, ������ ���� �� �ִ�. 
//FileStorage, FileNode

//xml ���� ���� 
//< ? xml version = "1.0" ? >
//<opencv_storage>
//<name>"�̵���"< / name>
//< age>20 < / age >
//<university>"�뱸���縯���б�"< / university>
//<picture>
//mine1.jpg mine2.jpg mine3.jpg< / picture>
//<hardware>
//< cpu>25 < / cpu >
//< mainboard>10 < / mainboard >
//< ram>6 < / ram > < / hardware>
//< vector>
//1 2 3 4 5 6 < / vector >
//<Mat type_id = "opencv-matrix">
//< rows>2 < / rows >
//< cols>3 < / cols >
//<dt>i< / dt>
//< data>
//1 2 3 4 5 6 < / data > < / Mat>
//<Point>
//1.0500000000000000e+01 200.< / Point>
//< Rect>
//10 200 100 200 < / Rect >
//< / opencv_storage>

int main() {

	FileStorage fs("test.xml", FileStorage::WRITE);
	string name = "�̵���";
	fs << "name" << name; 
	fs << "age" << 20;
	fs << "university" << "�뱸���縯���б�";
	fs << "picture" << "[" << "mine1.jpg" << "mine2.jpg" << "mine3.jpg" << "]";

	fs << "hardware" << "{";						//��� �̸� �� ���� ��� ���� 
	fs << "cpu" << 25;								//Ű �̸� �� ���� ������ 
	fs << "mainboard" << 10;
	fs << "ram" << 6 << "}";				

	int data[] = { 1,2,3,4,5,6 };
	vector<int> vec(data, data + sizeof(data) / sizeof(float));	//�迭�� ���� �ʱ�ȭ 
	fs << "vector" << vec;										//���� ����
	Mat m(2, 3, CV_32S, data);
	fs << "Mat" << m;											//������� 


	Point2d pt(10.5, 200);
	Rect rect(pt, Size(100, 200));	
	fs << "Point" << pt;										//Point ���� 
	fs << "Rect" << rect;										//Rect  ���� 

	fs.release();

	return 0;
}

