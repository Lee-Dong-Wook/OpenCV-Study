#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//4.2.4 ���콺 �� Ʈ���� �̺�Ʈ ��� 

string title = "Ʈ���� �̺�Ʈ", bar_name = "��� ��";
Mat image;

void onChange(int value, void *userdata) {				//Ʈ���� �ݹ� �Լ� ���� 

	int add_value = value - 130;						//-126~129 ���� 
	cout << "�߰� ȭ�� ��" << add_value << endl;

	Mat tmp = image + add_value;						//���� ��Ŀ� -126~129 ���̰� �����ϱ� 
	imshow(title, tmp);
}

void onMouse(int event, int x, int y, int flags, void *param) {		

	switch (event) {									//event ���� ���� ��ư ���� ���� 				

	case EVENT_LBUTTONDOWN:								//������ ��ư Ŭ�� �� ���� ��� 10�� ���� 
		cout << "���콺 ���ʹ�ư ������" << endl;
		add(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0)); //Ʈ���� ��ġ ���� 
		imshow(title, image);
		
		break;

	case EVENT_RBUTTONDOWN:								//���� ��ư Ŭ�� �� ���� ��� 10�� ���� 
		cout << "���콺 �����ʹ�ư ������" << endl;
		subtract(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0)); //Ʈ���� ��ġ ���� 
		imshow(title, image);
		break;
	}
}

int main() {

	int value = 130;
	image = Mat(300, 500, CV_8UC1, Scalar(120));			//1ä�� uchar ��� ���� 

	namedWindow(title, WINDOW_AUTOSIZE);					//������ ����
	createTrackbar("��Ⱚ", title, &value, 255, onChange);	//Ʈ���� �̸�, Ʈ���� ����� â�̸�, Ʈ���� ���氪, �ִ밪, �ݹ��Լ� �̸� 
	setMouseCallback(title,onMouse,0);
	imshow(title, image);
	waitKey(0);
	return 0;
}


