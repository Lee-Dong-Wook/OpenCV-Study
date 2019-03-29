#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.5.1 ī�޶� ������ �б� 
//VideoCapture Ŭ������ �̿��Ͽ� ���� ����, ī�޶󿡼� �������� ������ ��Ŀ� ���尡�� 
//VideoCapture::get() �̿� 

//���ڿ� ��� �Լ� - �׸��� ȿ�� 
void put_string(Mat &frame, string text, Point pt, int value) {

	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;								//�꼼���� ��Ʈ 

	//void putText(InputOutputArray img, const String& text, Point org, int fontFace, double fontScale, Scalar color,
	//				int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false);
	putText(frame, text, shade, font, 0.7, Scalar(0,0,0),2);			//�׸��� ȿ��	
	putText(frame, text,    pt, font, 0.7, Scalar(120, 200, 90), 2);	//�ۼ� ���� 	
}

int main() {

	VideoCapture capture(0);											//����ĸ�� ��ü ���� �� ���� 
	if (!capture.isOpened()) {											//���� ���� ����ó�� 
		
		cout << " ī�޶� ������� �ʾҽ��ϴ�. " << endl; 
		exit(1);
	}

	//ī�޶� �Ӽ� ȹ�� �� ��� 
	cout << "�ʺ� " << capture.get(CAP_PROP_FRAME_WIDTH)		<< endl;	//ī�޶� �Ӽ� ���� ��� 
	cout << "���� " << capture.get(CAP_PROP_FRAME_HEIGHT)	<< endl;
	cout << "���� " << capture.get(CAP_PROP_EXPOSURE)		<< endl;
	cout << "��� " << capture.get(CAP_PROP_BRIGHTNESS)		<< endl;

	for (;;) {

		Mat frame;				
		capture.read(frame);											//ī�޶� ����ޱ� 
		
		put_string(frame, "EXPOS : ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE)); //ī�޶� ���� �Ӽ� 
		imshow("ī�޶� ���󺸱�", frame);
		if (waitKey(30) >= 0) break;									//30ms ����, esc �Է½� ���� 	
	}

	return 0;
}

