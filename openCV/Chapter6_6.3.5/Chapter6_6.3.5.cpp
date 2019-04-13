#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.5 히스토그램 스트래칭 

//명암도에서 영상이 선명하고 깨끗하게 보이려면 어두운 부분에서 밝은 부분까지 고루 분포되야한다.
//그렇지 않은 영상의 히스토그램을 보면 특정 구간으로 치우쳐저 있다. 
//히스토그램 분포가 좁아 영상 대비가 좋지 않은 영상을 개선할 수 있는 알고리즘이 히스토그램 스트레칭(histogram stretching)이다.

//히스토그램 분포가 바뀐다는 것은 영상 내의 화소값의 분포가 바뀐다는 것. 영상의 화질도 변경되고 개선 된다는 것이다. 
//스트레칭을 하려면 x축 위에서 빈도값이 존제하는 가장 낮은 화소값(low value)와 가장 높은 화소값(high value)를 알아야한다. 
//가장 낮은 값을 0으로 당기고 가장 높은 값은 255로 당긴다

//공식
//새 화소값 = (화소 값 - low) * 255/x변화량,  x변화량 = high - low

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

	hist_img = Mat(size, CV_8U, Scalar(255));				//그래프 바탕이미지 행렬 
	float bin = (float)hist_img.cols / hist.rows;			//한 계급의 너비 256/200 	= 1.28

	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);	//최솟값이 0, 최댓값이 그래프 영상의 높이(hist_img.rows)값을 갖도록 히스토그램 빈도값 조정


	for (int i = 0; i < hist.rows; i++) {

		float	start_x = i * bin;							//시작,종료좌표 계산, start_x는 막대 한칸의 크기(bin)에 현재 인덱스i를 곱하고		
		float	end_x = (i + 1) * bin;						//end_x는 한칸 뒤의 인덱스(i+1)을 곱한다. 

		Point2f pt1(start_x, 0);							//막대 사각형 시작 x좌표 start_x, 0					
		Point2f pt2(end_x, hist.at<float>(i));				//막대 사각형 종료 y좌표 end_x, 빈도값 
															//시작좌표와 종료좌표 사이의 거리는 bin = hist_img.cols(그래프너비) / hist.rows(계급개수)?

		if (pt2.y > 0) {									//해당 화소가 1개라도 있다면 막대 사각형 그리기
			rectangle(hist_img, pt1, pt2, Scalar(0), -1);	//해당좌표에 내부를 채우는 사각형 그리기 
		}
	}
	flip(hist_img, hist_img, 0);							//x축 기준 영상 뒤집기 
}


int search_valueIdx(Mat hist, int bias = 0) {							//히스토그램 빈도가 존재하는 첫,마지막 위치 검색 

	for (int i = 0; i < hist.rows; i++) {
		int idx = abs(bias - i);										//검색 위치 (처음 or 마지막)
		if (hist.at<float>(idx) > 0) return idx;						//위치 반환 	
	}
	return -1;															//대상 없음 반환,모든 빈도값이 0일때 
}

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", 0);	//명암도 영상 로드 
	CV_Assert(!image.empty());

	Mat hist, hist_dst, hist_img, hist_dst_img;
	int histsize = 64, ranges = 256;				//계급 개수 및 화소범위

	calc_Histo(image, hist, histsize,ranges);

	float bin_width		= (float)ranges / histsize;						//계급 너비 
																		//계급 개수와 화소 범위로 계급 너비를 계산
																		//계급개수가 화소범위와 다를 경우를 위함 계급너비는 1픽셀이 아닐 수 있다.
	int   low_value		= (int)(search_valueIdx(hist, 0) * bin_width);	//최저 화소값
	int   high_value    = (int)(search_valueIdx(hist, hist.rows-1) * bin_width);	//최고 화소 값

	cout << "high_value = " << high_value << endl; 
	cout << "low_value = " << low_value << endl;

	int d_value = high_value - low_value;											//변화량 
	Mat dst = (image - low_value) * (255.0 / d_value);								//히스토그램 스트래칭 


	calc_Histo(dst, hist_dst, histsize, ranges);									//결과영상 히스토그램 재계산 
	draw_histo(hist, hist_img);														//원본영상 히스토그램 그리기			
	draw_histo(hist_dst, hist_dst_img);												//결과영상 히스토그램 그리기 	

	imshow("image", image);
	imshow("hist_img", hist_img);
	imshow("dst_image", dst);
	imshow("hist_dst_img", hist_dst_img);

	waitKey();
	return 0;
}