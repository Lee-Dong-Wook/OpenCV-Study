#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.2.1 채널 분리 및 합성 
//컬러 영상은 R,G,B 각기 독립적인 2차원 정보를 합쳐 놓은 배열
//c언어에서 3차원행렬로 구현된 것과 달리 openCV에선 실제 영상 3채널 Mat 경우 pixel-wise 방식으로 순회한다. 
//1pixel은 BGR로 되어있고 1행 3열로 표현된다. 
//실제로 처리할 때 각 R,G,B 채널을 따로 모아 처리하는 방식이다. 

int main() {

	Mat ch0(3, 4, CV_8U, Scalar(10));		//단일 채널 생성, 1채널 uchar 행렬 선언 및 초기화  
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));

	Mat bgr_arr[] = { ch0, ch1, ch2 };		//채널 배열, 단일 채널 3개를 원소로 갖는 배열  
	Mat bgr;								//채널 합성 행렬 

	merge(bgr_arr, 3, bgr);					//채널 합성, 입력이 배열일 경우 합성할 행렬 개수 입력 
	vector<Mat> bgr_vec;
	split(bgr, bgr_vec);					//3채널 행렬을 3개 단일 행렬을 갖는 벡터로 분리  

	cout << "[ch0] = " << endl << ch0 << endl;
	cout << "[ch1] = " << endl << ch1 << endl;
	cout << "[ch2] = " << endl << ch2 << endl;

	cout << "[bgr] = " << endl << bgr << endl;
	cout << "[bgr_vec[0]] = " << endl << bgr_vec[0] << endl;
	cout << "[bgr_vec[1]] = " << endl << bgr_vec[1] << endl;
	cout << "[bgr_vec[2]] = " << endl << bgr_vec[2] << endl;
	waitKey();
	return 0;
}

