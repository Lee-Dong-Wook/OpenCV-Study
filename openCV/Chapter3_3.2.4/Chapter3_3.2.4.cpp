#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	//Matx Ŭ���� �̿��� �ʱ�ȭ
	//Ŭ���� �̸��� <,> �ȿ� ����� �ڷ���, ���, ���� ���� 
	//Matx.hpp ��������� �Ϻ� ���� 
	/*typedef Matx<float, 1, 2> Matx12f;
	typedef Matx<double, 1, 2> Matx12d;
	typedef Matx<float, 1, 3> Matx13f;
	typedef Matx<double, 1, 3> Matx13d;
	typedef Matx<float, 1, 4> Matx14f;
	typedef Matx<double, 1, 4> Matx14d;
	typedef Matx<float, 1, 6> Matx16f;
	typedef Matx<double, 1, 6> Matx16d;

	typedef Matx<float, 2, 1> Matx21f;
	typedef Matx<double, 2, 1> Matx21d;
	typedef Matx<float, 3, 1> Matx31f;
	typedef Matx<double, 3, 1> Matx31d;
	typedef Matx<float, 4, 1> Matx41f;
	typedef Matx<double, 4, 1> Matx41d;
	typedef Matx<float, 6, 1> Matx61f;
	typedef Matx<double, 6, 1> Matx61d;

	typedef Matx<float, 2, 2> Matx22f;
	typedef Matx<double, 2, 2> Matx22d;
	typedef Matx<float, 2, 3> Matx23f;
	typedef Matx<double, 2, 3> Matx23d;
	typedef Matx<float, 3, 2> Matx32f;
	typedef Matx<double, 3, 2> Matx32d;

	typedef Matx<float, 3, 3> Matx33f;
	typedef Matx<double, 3, 3> Matx33d;

	typedef Matx<float, 3, 4> Matx34f;
	typedef Matx<double, 3, 4> Matx34d;
	typedef Matx<float, 4, 3> Matx43f;
	typedef Matx<double, 4, 3> Matx43d;

	typedef Matx<float, 4, 4> Matx44f;
	typedef Matx<double, 4, 4> Matx44d;
	typedef Matx<float, 6, 6> Matx66f;
	typedef Matx<double, 6, 6> Matx66d;*/

	//�⺻ ���� ��� 
	Matx<int, 3, 3>			m1(1, 2, 3, 4, 5, 6, 7, 8, 9);		//Matx ��ü ����� ���� ���� �ʱ�ȭ 
	Matx<float, 2, 3>		m2(1, 2, 3, 4, 5, 6);
	Matx<double, 3, 5>		m3(3, 4, 5, 7);

	//���� ���� ���
	Matx23d m4(3, 4, 5, 6, 7, 8);
	Matx34d m5(1, 2, 3, 10, 11, 12, 13, 14, 15);
	Matx66f m6(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	//��� ���� ����
	cout << "m5(0,0) = " << m5(0, 0) << " m5(1,0) = " << m5(1, 0) << endl;
	cout << "m6(0,1) = " << m6(0, 1) << " m6(1,3) = " << m6(1, 3) << endl;

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m5] = " << endl << m5 << endl;
	cout << "[m6] = " << endl << m6 << endl;
	return 0;

}