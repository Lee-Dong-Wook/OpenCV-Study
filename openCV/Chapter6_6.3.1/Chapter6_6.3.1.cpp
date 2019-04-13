#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.1 영상 히스토 그램 계산 

//히스토그램을 수학적으로 보면 "관측 값의 개수를 겹치지 않는 다양한 계급으로 표시하는 것"
//어떤 데이터가 얼마나 많을지를 나타내는 도수 분포표를 그래프로 나타낸 것
//가로축이 계급(변수의 구간), 세로 축이 도수(관측 값의 개수 즉, 빈도수)

void calc_histo(Mat image, Mat &hist, int bins, int range_max = 256) {

	hist = Mat(bins, 1, CV_32F, Scalar(0));		//계급 수 만큼 행을 갖는 히스토그램 누적 행렬 
												//히스토그램 결과저장 
												//bins 개수로 행렬의 행수 지정. 누적값 범위를 고려해 float형, 0으로 초기화 	

	float gap = range_max / (float)bins;		//계급 간격
												//화소값 범위 0~range_max, 계급 개수는 bins 
												// 256.0/256.0 = 1.0
												

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {

			int idx = int(image.at<uchar>(i, j) / gap);			//화소가 속한 계급 위치 계산
																//화소 값을 gap으로 나누어 각 화소가 속하는 계급을 계산하여 idx에 저장 
																//해당화소(0~255) / gap(=1)을 하니 해당화소가 나오고 idx에 저장됨 

			hist.at<float>(idx)++;								//해당 계급에 값 누적
																//idx를 인덱스로 hist행렬 원소에 접근, 그 값을 1씩 증가 
																//해당 화소값이 출현시 그 계급의 출현 빈도수를 증가 		
																//256행 1열의 hist 행렬 
																//256행 중 포함되는 idx가 있으면 1씩 증가 	
		}
	}
}

int main() {
	
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee3.jpg");
	CV_Assert(!image.empty());

	Mat hist;
	calc_histo(image, hist, 256);					//히스토그램 계산, 여기서는 인수가 원본영상, 히스토그램 행렬, 계급 수
													//range_max 선언시 256으로 초기화 되었으므로 인수를 적지 않으면 256이다. 
	cout << hist.t() << endl;						//세로인 행렬을 전치하여 가로 그래프로 변형  

	imshow("image", image);
	

	waitKey();
	return 0;
}