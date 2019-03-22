#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//RectŬ���� ���� 
	//1) x��ǥ, y��ǥ, �ʺ�, ���� 
	//2) ������ǥ(pt1)�� ũ��(sz)
	//3) ������ǥ(pt1)�� ������ǥ(pt2)

	//Rect Ŭ���� ��� 
	//1) rect = rect+-point �簢���� ���� �����̵�
	//2) rect = rect+-size  �簢�� ũ���� ���� 
	//3) rect = rect1&rect2 �簢���� �������� 
	//4) rect = rect1|rect2 rect2�� rect3 ������ ��� �����ϴ� ���� 

	Size2d sz(100.5, 60.6);							//�簢�� ũ��
	Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);		//���� ��ǥ �� ���� ��ǥ 

	Rect_<int>		rect1(10, 10, 30, 50);			// 1) x = 10, y = 10, �ʺ� = 30, ���� = 50 
	Rect_<float>	rect2(pt1, pt2);                // 2) ������ġ pt1, ������ġ pt2
	Rect_<double>	rect3(Point2d(20.5, 10), sz);   // 3)  ���� ��ǥ�� Size_ ��ü�� ���� 
	Rect_<float>		rect7(pt1, sz);

	Rect	rect4 = rect1 + (Point)pt1;				//rect1, pt1��ŭ �����̵�. ������ǥ ���� 
	Rect2f	rect5 = rect2 + (Size2f)sz;             //rect2, rect2 + sz �簢�� ����. ũ�� ���� 
	Rect2d	rect6 = rect1 & (Rect)rect2;            //�λ簢�� �������� ���ϴ� ����� ���� ���� ���ƾ���

	cout << "rect3 = " << rect3.x << ", "<< rect3.y << ","; 
	cout << rect3.width << "x" << rect3.height << endl;
	cout << "rect7 = " << rect7.width << "x" << rect3.height << endl;
	cout << "rect7 = " << rect7.area() << endl;

	cout << "rect4 = "<< rect4.tl() << " " << rect4.br() << endl;
	cout << "rect5 ũ�� = "<< rect5.size() << endl;
	cout << "[rect6] = "<< rect6 <<endl;
	

	return 0;
}