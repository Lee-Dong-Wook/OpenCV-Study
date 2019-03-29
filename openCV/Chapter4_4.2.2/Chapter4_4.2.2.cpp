#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

	//4.2.2 ���콺 �̺�Ʈ ���� 
	//openCV���� �����ϴ� �ݹ� �Լ��� ���� �̺�Ʈ�� �߻� �� ���� 
	//������ �Լ� ȣ�� ����� �ƴ� � �̺�Ʈ�� �߻��ϰų� Ư�� ������ �������� �� �ý��ۿ��� �����ڰ� ����� �Լ��� ȣ�� �ϴ� ���
	//���콺 �̺�Ʈ ��� : cv::setMouseCallback()

void onMouse(int, int, int, int, void *);		//���콺 �ݹ� �Լ� ����




int main() {

	Mat image(200, 300, CV_8U);
	image.setTo(255);													//image ��� �ʱ�ȭ - ��� ���� 
	imshow(" ���콺 �̺�Ʈ1 ", image);									//â ���� 
	imshow(" ���콺 �̺�Ʈ2 ", image);
	
	setMouseCallback(" ���콺 �̺�Ʈ1 ", onMouse, 0);							//���콺 �̺�Ʈ �ݹ��Լ� �ý��ۿ� ��� 	
	setMouseCallback(" ���콺 �̺�Ʈ2 ", onMouse, 0);
	waitKey(0);
	
	return 0;
}

void onMouse(int event, int x, int y, int flags, void *param) {			//�ݹ��Լ� ���� 

	switch (event) {													//event ���� ���� ��ư ���� ���� 

	case EVENT_LBUTTONDOWN:
		cout << "���콺 ���ʹ�ư ������" << endl;
		break;

	case EVENT_RBUTTONDOWN:
		cout << "���콺 �����ʹ�ư ������" << endl;
		break;

	case EVENT_RBUTTONUP:
		cout << "���콺 �����ʹ�ư ����" << endl;
		break;

	case EVENT_LBUTTONDBLCLK:
		cout << "���콺 ���ʹ�ư ����Ŭ��" << endl;
		break;

	}
}
