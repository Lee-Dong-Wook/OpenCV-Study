#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.6.1 FileStorage클래스로 데이터 저장 
//openCV에서는 Mat,Rect,Point,Size 등의 다양한 자료구조를 XML이나 YAML 형식의 파일로 저장, 파일을 읽을 수 있다. 
//FileStorage, FileNode

//xml 파일 내용 
//< ? xml version = "1.0" ? >
//<opencv_storage>
//<name>"이동욱"< / name>
//< age>20 < / age >
//<university>"대구가톨릭대학교"< / university>
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
	string name = "이동욱";
	fs << "name" << name; 
	fs << "age" << 20;
	fs << "university" << "대구가톨릭대학교";
	fs << "picture" << "[" << "mine1.jpg" << "mine2.jpg" << "mine3.jpg" << "]";

	fs << "hardware" << "{";						//노드 이름 및 매핑 노드 지정 
	fs << "cpu" << 25;								//키 이름 및 저장 데이터 
	fs << "mainboard" << 10;
	fs << "ram" << 6 << "}";				

	int data[] = { 1,2,3,4,5,6 };
	vector<int> vec(data, data + sizeof(data) / sizeof(float));	//배열로 벡터 초기화 
	fs << "vector" << vec;										//벡터 저장
	Mat m(2, 3, CV_32S, data);
	fs << "Mat" << m;											//행렬저장 


	Point2d pt(10.5, 200);
	Rect rect(pt, Size(100, 200));	
	fs << "Point" << pt;										//Point 저장 
	fs << "Rect" << rect;										//Rect  저장 

	fs.release();

	return 0;
}

