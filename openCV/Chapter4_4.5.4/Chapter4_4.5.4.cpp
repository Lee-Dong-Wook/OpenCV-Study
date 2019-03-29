#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

////4.5.4 ���� ���� �б� 
//������ 


//���ڿ� ��� �Լ� - �׸��� ȿ�� 
void put_string(Mat &frame, string text, Point pt, int value) {

	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;								//�꼼���� ��Ʈ 

	//void putText(InputOutputArray img, const String& text, Point org, int fontFace, double fontScale, Scalar color,
	//				int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false);
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);			//�׸��� ȿ��	
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);		//�ۼ� ���� 	
}
int main() {


	VideoCapture capture;
	capture.open("C:/Users/Raynor/Desktop/openCVEXImage/Ex_video.avi");			//������ ���� ���� 
	CV_Assert(capture.isOpened());												 

	double frame_rate	= capture.get(CAP_PROP_FPS);							//�ʴ� ������ �� 	
	int	   delay		= 1000 / frame_rate;									//�����ð� 
	int	   frame_cnt	= 0;													//���� �������� ��ȣ 
	Mat    frame;																//���� �������� ��ȣ 

	while (capture.read(frame)) {												//������ �ݺ� ��� 

		if (waitKey(delay) >= 0) break;											//�����Ӱ� �����ð� ����, 1�ʴ�  

		if (frame_cnt < 100);
		else if (frame_cnt < 200) frame -= Scalar(0, 0, 100);
		else if (frame_cnt < 300) frame -= Scalar(100, 0, 0);
		else if (frame_cnt < 400) frame = frame * 1.5;
		else if (frame_cnt < 500) frame = frame * 0.5; 

		put_string(frame," frame_cnt : ",Point(20, 50), frame_cnt);
		imshow(" ������ �����б� ", frame);

		frame_cnt++;
	}

	
	return 0;
}

