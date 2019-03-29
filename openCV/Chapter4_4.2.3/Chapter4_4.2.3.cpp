#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.2.3 Ʈ���� �̺�Ʈ ���� 
//������ ���� ������ Ư���� ���� �����ϰ��� �Ҷ� ���. ��ũ�� �� , �����̴� �� �� 

string title = "Ʈ���� �̺�Ʈ";
Mat image;

void onChange(int value, void *userdata) {				//Ʈ���� �ݹ� �Լ� ���� 

	int add_value = value - 130;						//-126~129 ���� 
	cout << "�߰� ȭ�� ��" << add_value << endl; 
    
	Mat tmp = image + add_value;						//���� ��Ŀ� -126~129 ���̰� �����ϱ� 
	imshow(title, tmp);
}


int main() {

	int value = 128; 
	image = Mat(300, 400, CV_8UC1, Scalar(120));		//1ä�� uchar ��� ���� 

	namedWindow(title, WINDOW_AUTOSIZE);				//������ ����
	createTrackbar("��Ⱚ",title,&value,255,onChange);	//Ʈ���� �̸�, Ʈ���� ����� â�̸�, Ʈ���� ���氪, �ִ밪, �ݹ��Լ� �̸� 

	imshow(title, image);

	waitKey(0);
	return 0; 
}


