#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.2 cv::calcHist() 이용

//6.3.1은 실제로 히스토그램을 구현했지만 opencv에 히스토그램라이브러리가 있다. 

  //void calcHist(const Mat *image,		원본영상 배열 - CV_8U or CV_32F 형으로 크기가 같아야함
		//		  int nimage,			원본영상 개수 
		//		  const int *channels,  히스토그램 계산에 사용되는 차원 목록 
		//		  InputArray mask,      특정 영역만 계산하기 위한 마스크 행렬 - 입력 영상과 같은 크기의 8비트 배열 
		//		  OutputArray hist,     계산된 히스토그램이 출력되는 배열 
		//		  int dims,				히스토그램의 차원 수 
		//		  const int *histSize,	각 차원의 히스토그램 배열 크기 - 계급(bin)의 개수 
		//		  float **ranges,       각 차원의 히스토그램 범위 
		//		  bool uniform,			히스토그램이 균일(uniform)한지를 나타내는 플래그
		//		  bool accumulate);		누적플래그 - 여러 배열에서 단일 히스토그램을 구할 때 사용 

void calc_Histo(const Mat& image, Mat &hist, int bins, int range_max = 256) {

	int			 histSize[]		= { bins };						//히스토그램 계급 개수 
	float		 range[]		= { 0, (float)range_max };		//0번 채널 화소 값 범위 
	int			 channels[]		= { 0, };						//채널 목록 - 단일 채널 
	const float* ranges[]	    = { range };					//모든 채널 화소 범위 

	//원본영상, 영상개수, 채널, 마스크행렬, 출력행렬, 차원수, 계급개수, 화소범위
	calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);	 //histSize : calcHist는  다중 채널행렬에 대해 각 채널의 계급 개수를 배열로 지정
}																		 //ranges   : 각 채널의 범위를 모아 모든 채널의 범위 지정
																		 //           range[]배열이 한 채널범위고 이것이 모여 다중 채널 배열로구성 
																	     //Mat()	: 마스크행렬 지정하지 않으면 기본 자료형만 제시 		

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee3.jpg");
	CV_Assert(!image.empty());

	Mat hist;
	calc_Histo(image, hist, 256);					//히스토그램 계산, 여기서는 인수가 원본영상, 히스토그램 행렬, 계급 수
													//range_max 선언시 256으로 초기화 되었으므로 인수를 적지 않으면 256이다. 
	cout << hist.t() << endl;						//세로인 행렬을 전치하여 가로 그래프로 변형  

	imshow("image", image);


	waitKey();
	return 0;
}