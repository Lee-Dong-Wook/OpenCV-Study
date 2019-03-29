#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

////4.5.4 비디오 파일 읽기 
//실행결과 


//문자열 출력 함수 - 그림자 효과 
void put_string(Mat &frame, string text, Point pt, int value) {

	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;								//산세리프 폰트 

	//void putText(InputOutputArray img, const String& text, Point org, int fontFace, double fontScale, Scalar color,
	//				int thickness = 1, int lineType = LINE_8, bool bottomLeftOrigin = false);
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);			//그림자 효과	
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);		//작성 문자 	
}
int main() {


	VideoCapture capture;
	capture.open("C:/Users/Raynor/Desktop/openCVEXImage/Ex_video.avi");			//동영상 파일 개방 
	CV_Assert(capture.isOpened());												 

	double frame_rate	= capture.get(CAP_PROP_FPS);							//초당 프레임 수 	
	int	   delay		= 1000 / frame_rate;									//지연시간 
	int	   frame_cnt	= 0;													//현재 프레임의 번호 
	Mat    frame;																//현재 프레임의 번호 

	while (capture.read(frame)) {												//프레임 반복 재생 

		if (waitKey(delay) >= 0) break;											//프레임간 지연시간 지정, 1초당  

		if (frame_cnt < 100);
		else if (frame_cnt < 200) frame -= Scalar(0, 0, 100);
		else if (frame_cnt < 300) frame -= Scalar(100, 0, 0);
		else if (frame_cnt < 400) frame = frame * 1.5;
		else if (frame_cnt < 500) frame = frame * 0.5; 

		put_string(frame," frame_cnt : ",Point(20, 50), frame_cnt);
		imshow(" 동영상 파일읽기 ", frame);

		frame_cnt++;
	}

	
	return 0;
}

