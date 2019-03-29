#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//4.3.5 ���콺 �̺�Ʈ �� �׸��� ���� 

string title = "�̺�Ʈ �׸���";		//�������� 
Mat	   image;

void onMouse(int event, int x, int y, int flags, void *param) {

	static Point pt(-1, -1);									//�ݹ��Լ� ȣ��� �������� �����ǰ� ���������� ���� 
	if (event == EVENT_LBUTTONDOWN) {							//���� ���콺 ��ư Ŭ���� ��ġ ���� 
		
		if (pt.x < 0) pt = Point(x, y);							//x��ǥ�� 0���� ������ �Է��� ��ǥ�� ���� 
		else {
			rectangle(image, pt, Point(x, y), Scalar(50), 2);	//������ǥ �� �׸��� 
			
			imshow(title, image);
			pt = Point(-1, -1);									//���� ��ǥ �ʱ�ȭ 
		}
	}

	else if (event == EVENT_RBUTTONDOWN) {

		if (pt.x < 0) pt = Point(x, y);
		else {
			Point2d pt2 = pt - Point(x, y);
			int radius = (int)sqrt((pt2.x * pt2.x) + (pt2.y * pt2.y)); //�� ��ǥ�� �Ÿ� 
			circle(image, pt, radius, Scalar(150), 2);

			imshow(title, image);
			pt = Point(-1, -1);		
		}
	}
}

int main() {

	image = Mat(300, 500, CV_8UC1, Scalar(255));
	imshow(title, image);			
	
	setMouseCallback(title, onMouse, 0);							//�ݹ��Լ� ��� 

	waitKey(0);
	return 0;
}

