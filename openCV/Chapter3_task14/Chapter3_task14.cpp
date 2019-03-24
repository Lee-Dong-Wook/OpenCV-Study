#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  
	//��ǥ�� 10,10 �����̵� , 20x30��ŭ ����  // ����Ʈ ����, ������� ���� 
	//size.width, size.hieght, size.area(), size ��ü ���� ����x���� ��� 

	//�簢�� ���� Rect(������ǥx,������ǥy,�ʺ�w,����h)
	Rect_<float>  rect(30.0f, 40.0f, 100.0f, 200.0f);

	cout << " �ʱ�簢�� ���� "<< rect << endl; 
	cout << " �ʱ�簢���� ���� "<<rect.area() << endl<<endl; 

	//��ǥ�� ũ�� ��ü ���� 
	Size2f sz(20,30);
	Point2f pt(10, 10);

	rect = rect + sz;
	cout << " ũ�� ���� �� �簢�� ���� " << rect << endl;
	cout << " ũ�� ���� �� �簢�� ���� " << rect.area() << endl<<endl;
	
	rect = rect + pt; 
	cout << " ��ǥ �̵� �� �簢�� ���� " << rect << endl;
	

	return 0;
}