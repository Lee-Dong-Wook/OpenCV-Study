#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.5.1 카메라 프레임 읽기 
//VideoCapture 클래스를 이용하여 비디오 파일, 카메라에서 프레임을 가져와 행렬에 저장가능 
//VideoCapture::get() 이용 

//문자열 출력 함수 - 그림자 효과 
void put_string(Mat &frame, string text, Point pt, int value) {

	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;								//산세리프 폰트 

	//void putText(InputOutputArray img, const String& text, Point org, int fontFace, double fontScale, Scalar color,
	//				int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false);
	putText(frame, text, shade, font, 0.7, Scalar(0,0,0),2);			//그림자 효과	
	putText(frame, text,    pt, font, 0.7, Scalar(120, 200, 90), 2);	//작성 문자 	
}

int main() {

	VideoCapture capture(0);											//비디오캡쳐 객체 선언 및 연결 
	if (!capture.isOpened()) {											//비디오 파일 예외처리 
		
		cout << " 카메라가 연결되지 않았습니다. " << endl; 
		exit(1);
	}

	//카메라 속성 획득 및 출력 
	cout << "너비 " << capture.get(CAP_PROP_FRAME_WIDTH)		<< endl;	//카메라 속성 정보 얻기 
	cout << "높이 " << capture.get(CAP_PROP_FRAME_HEIGHT)	<< endl;
	cout << "노출 " << capture.get(CAP_PROP_EXPOSURE)		<< endl;
	cout << "밝기 " << capture.get(CAP_PROP_BRIGHTNESS)		<< endl;

	for (;;) {

		Mat frame;				
		capture.read(frame);											//카메라 영상받기 
		
		put_string(frame, "EXPOS : ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE)); //카메라 노출 속성 
		imshow("카메라 영상보기", frame);
		if (waitKey(30) >= 0) break;									//30ms 지연, esc 입력시 종료 	
	}

	return 0;
}

