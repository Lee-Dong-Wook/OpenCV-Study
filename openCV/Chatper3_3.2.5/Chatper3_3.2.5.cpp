#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//Mat Ŭ������ �پ��� �Ӽ� p.92 Ȯ�� 
	//4 = row(��), 3 = col(��) 
	//CV_32F = ����� ����(����� �ڷ���)�� ���� ��, C3 = ä��
	//type = ����� ������ Ÿ��(�ڷ��� + ä�� ��)��ȯ �ڷ������� ���� 3��Ʈ + ä�� ���� ���� 3��Ʈ 

	Mat m1(5, 3, CV_32FC3);
	cout << " ���� �� = " <<m1.dims << endl;		//2
	cout << " �� ���� = " <<m1.rows << endl;		//5    
	cout << " �� ���� = " <<m1.cols << endl;		//3
	cout << " ��� ũ�� = " << m1.size() << endl << endl;				  // 3x5=15

	cout << " ��ü ���� ���� =  " <<m1.total() << endl;					  // 3x5 = 15 
	cout << " �� ������ ũ�� =  " <<m1.elemSize() << endl;				 // ä�� 3�� �� �� 4byte �� 3��, float32bit = 4byte x 3 = 12byte 
	cout << " ä�δ� �� ������ ũ�� =  " <<m1.elemSize1() << endl << endl;//float�� 32bit ä�� 1�� = 4byte 

	cout << " ä�� =  " << m1.channels() << endl;		//3 
	cout << " ���� =  " << m1.depth() << endl;			//���ΰ� 5 
	cout << " Ÿ�� =  " <<m1.type() << endl;
	cout << " Ÿ��(ä�� �� ����) =  " <<((m1.channels() -1) << 3) + m1.depth() << endl; // 3 -1 = 2 = 2����10 , 10�� �������� 3
																					   // 1000 = 16, 16+5 = 21
	
	cout << " step =  " << m1.step << endl;			//����� �� ���� �����ϴ� ����Ʈ �� 12byte x 3�� =  36 
	cout << " step1() = " << m1.step1() << endl;	//

	return 0;
}