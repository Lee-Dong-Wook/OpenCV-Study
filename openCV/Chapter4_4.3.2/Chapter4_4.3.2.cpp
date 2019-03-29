#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.3.2 글자쓰기 
//cv::putText()
//표시 문자열의 시작 좌표가 문자열의 오른쪽 하단임을 유의해야한다. 

int main() {

	Scalar olive(128, 128, 0), violet(221, 160, 221), brown(42, 42, 165);	//색상 지정 
	Point  pt1(20, 100), pt2(20, 200), pt3(20, 250);						//문자열 위치 좌표 

	Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));					//3채널 uchar 행렬 선언 및 흰색(255)초기화 

	putText(image, "SIMPLEX", Point(20, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(42, 42, 165));
	putText(image, "DUPLEX" , pt1, FONT_HERSHEY_DUPLEX, 2, olive);
	putText(image, "TRIPLEX", pt2, FONT_HERSHEY_TRIPLEX, 3, violet);
	putText(image, "ITALIC" , pt3, FONT_HERSHEY_PLAIN | FONT_ITALIC, 2, violet);

	imshow("글자쓰기", image);
	waitKey(0);	
	return 0;
}


