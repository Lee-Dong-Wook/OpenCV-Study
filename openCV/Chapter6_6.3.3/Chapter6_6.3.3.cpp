#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.3 히스토그램 그래프 그리기 

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

	int			 histSize[] = { bins };						//히스토그램 계급 개수 
	float		 range[] = { 0, (float)range_max };			//0번 채널 화소 값 범위 
	int			 channels[] = { 0, };						//채널 목록 - 단일 채널 
	const float* ranges[] = { range };						//모든 채널 화소 범위 

	//원본영상, 영상개수, 채널, 마스크행렬, 출력행렬, 차원수, 계급개수, 화소범위
	calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);	 //histSize : calcHist는  다중 채널행렬에 대해 각 채널의 계급 개수를 배열로 지정
}																		 //ranges   : 각 채널의 범위를 모아 모든 채널의 범위 지정
																		 //           range[]배열이 한 채널범위고 이것이 모여 다중 채널 배열로구성 
																		 //Mat()	: 마스크행렬 지정하지 않으면 기본 자료형만 제시 		


void draw_histo(Mat hist, Mat &hist_img, Size size = Size(256, 200)) {

	hist_img	= Mat(size, CV_8U, Scalar(255));				//그래프 바탕이미지 행렬 
	float bin	= (float)hist_img.cols / hist.rows;			//한 계급의 너비 256/200 	= 1.28
	
	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);	//최솟값이 0, 최댓값이 그래프 영상의 높이(hist_img.rows)값을 갖도록 히스토그램 빈도값 조정
															 							

	for (int i = 0; i < hist.rows; i++) {

		float	start_x		     = i * bin;					//시작,종료좌표 계산, start_x는 막대 한칸의 크기(bin)에 현재 인덱스i를 곱하고		
		float	end_x		     = (i + 1) * bin;			//end_x는 한칸 뒤의 인덱스(i+1)을 곱한다. 

		Point2f pt1(start_x, 0);							//막대 사각형 시작 x좌표 start_x, 0					
		Point2f pt2(end_x, hist.at<float>(i));				//막대 사각형 종료 y좌표 end_x, 빈도값 
															//시작좌표와 종료좌표 사이의 거리는 bin = hist_img.cols(그래프너비) / hist.rows(계급개수)?
																		
		if (pt2.y > 0) {									//해당 화소가 1개라도 있다면 막대 사각형 그리기
			rectangle(hist_img, pt1, pt2, Scalar(0), -1);	//해당좌표에 내부를 채우는 사각형 그리기 
		}
	}
	flip(hist_img, hist_img, 0);							//x축 기준 영상 뒤집기 
}
int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee3.jpg");
	CV_Assert(!image.empty());

	Mat hist, hist_img;
	calc_Histo(image, hist, 256);					//히스토그램 계산, 여기서는 인수가 원본영상, 히스토그램 행렬, 계급 수
													//range_max 선언시 256으로 초기화 되었으므로 인수를 적지 않으면 256이다. 
	
	draw_histo(hist, hist_img);

	imshow("image", image);
	imshow("hist_img", hist_img);

	waitKey();
	return 0;
}