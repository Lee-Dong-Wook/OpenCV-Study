#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.6 히스토그램 평활화 

//영상처리에서 히스토그램을 다루면 평활화가 반드시 따라온다. 
//히스토그램 평활화의 사전적 의미인 "분포의 균등"이라는 방법을 이용해 명암대비를 증가시킨다. 
//영상의 인지도 및 영상의 화질 개선이 가능 

//스트레칭은 분포가 좁은 영상을 스트레칭 하여 분포를 넓게 만듬. 하지만 분포가 좁지는 않지만 특정 부분
//에서 한쪽으로 치우친 명암 분포를 가진 영상도 있다. 

//이럴때는 히스토그램 평활화를 사용 

//평활화 과정
//1. 영상의 히스토그램 계산
//2. 히스토그램 빈도값에서 누적빈도수(누적합) 계산
//3. 누적 빈도수를 정규화(정규화 누적합)
//4. 결과 화소값 :입력화소 정규화 누적값 * 최대 화소값 

//누적 빈도수 계산 
//p.322 확인
//화소값 2인경우 화소값 0과 1의 빈도인 1과 5를 각각 자신의 빈도인 6과 누적시켜 결과적으로 12가 된다.
//마지막화소값7에 이르기까지 빈도수를 누적, 결과 전체 화소개수와 같은 16

//화소의 누적 빈도수를 전체 화소개수16으로 나누어 정규화하여 정규화 누적합을 계산
//정규화는 원소 중에서 최댓값으로 각 원소를 나누어 원소들의 값이 0~1사이 값을 가지게 표현 

//입력화소 2경우 정규화 누적합은 누적빈도수 12 / 전체화소 16 = 0.75
//평활화 결과 화소 값 = 0.75 * 7 = 5.25 , 평활화 결과 값은 5 
//화소가 2-> 5로 변경 

//cv::equalizeHist()이용과 직접 구현을 통해 차이점을 보자 

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

void create_hist(Mat img, Mat &hist, Mat &hist_img) {

	int histsize = 256, range = 256; 
	
	calc_Histo(img, hist, histsize, range);		
	draw_histo(hist, hist_img);
}

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg", 0);	//명암도 영상 로드 
	CV_Assert(!image.empty());

	Mat hist, dst1, dst2, hist_img, hist_img1, hist_img2;

	create_hist(image, hist, hist_img);											//히스토그램 및 그래프 그리기 

	//히스토그램 누적합계산
	Mat accum_hist = Mat(hist.size(), hist.type(), Scalar(0));
	
	accum_hist.at<float>(0) = hist.at<float>(0);
	for (int i = 1; i < hist.rows; i++) {

		accum_hist.at<float>(i) = accum_hist.at<float>(i-1) + hist.at<float>(i);	//히스토그램 빈도 행렬 
	}

	accum_hist /= sum(hist)[0];			//누적합의 정규화(전체 빈도수 / 계산된 누적합 = 0~1사이 값)
	accum_hist *= 255;					//정규화된 값을 0~255사이 화소값이 되게 변경, 평활화에 바로 적용을 위함 
	dst1 = Mat(image.size(), CV_8U);

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {				//원본 영상의 화소 값으로 정규화 누적합 행렬의 원소를 가져와 결과 영상의 화소값에 저장 
			int idx = image.at<uchar>(i, j);								//정규화 누적합 행렬을 LookUP테이블로 사용한 것 
			dst1.at<uchar>(i, j) = (uchar)accum_hist.at<float>(idx);		//입력 화소값으로 누적합 행렬 원소값을 가져와 목적영상 화소로 지정
		}
	}

	//Line 103 ~ 106 과 동일한 기능 
	//normalize(accum_hist, accum_hist, 0, 255, NORM_MINMAX);	//누적합의 정규화 
	//accum_hist.convertTo(accum_hist, CV_8U);				
	//LUT(image, accum_hist, dst1);							//룩업 테이블 적용 

	equalizeHist(image, dst2);								//openCV 히스토그램 평활화 라이브러리
	create_hist(dst1, hist, hist_img1);						//히스토그램 및 그래프 그리기 
	create_hist(dst2, hist, hist_img2);					

	imshow("image", image);
	imshow("user dst1", dst1);
	imshow("opencv dst2", dst2);
	imshow("hist_img", hist_img);							//원본 히스토그램
	imshow("user histo", hist_img1);							//사용자 평활화
	imshow("opencv histo", hist_img2);						//openCV 평활화 
	
	waitKey();
	return 0;
}