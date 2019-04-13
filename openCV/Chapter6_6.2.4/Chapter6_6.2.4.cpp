#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.4 행렬 합과 곱 연산을 통한 영상 합성 

//** 주의 이미지 크기가 같아야 실행가능 ** 
// 두 영상을 합치면 영상 합성이 되며 두 영상을 빼면 차영상(difference image)가 된다. differencial은 정말 많이 사용된다
//두개의 행렬을 합하게 되면 saturation_cast 연산으로 인해 255를 넘어서는 화소는 흰색으로 나타나 합성수행이 재대로되지 않는다.
//그렇기 때문에 특정 이미지에 가중치를 곱하는 방식이 있다. 

int main() {

	Mat image1 = imread("C:/Users/Raynor/Desktop/openCVEXImage/same1.jpg",IMREAD_GRAYSCALE);
	Mat image2 = imread("C:/Users/Raynor/Desktop/openCVEXImage/same2.jpg", IMREAD_GRAYSCALE);
	
	CV_Assert(!(image1.empty() || image2.empty()));			//예외 처리 

	double alpha = 0.6, beta = 0.7;							//곱셈 비율 

	Mat add_img1 = image1 + image2;								//영상 합성 행렬덧셈은 포화산술이 되므로 255보다 큰값은 255로 지정 
	Mat add_img2 = image1 * 0.5 + image2 * 0.5;					//각 이미지에 1/2을 곱하여 255이내 값으로 합성 
	Mat add_img3 = image1 * alpha + image2 * (1 - alpha);		//특정 이미지에 더 큰 비중을 준다
	Mat add_img4;

	addWeighted(image1, alpha, image2, beta, 0 , add_img4);		//각 행렬에 곱해지는 비율을 다르게 지정가능 하다. 
																//alpha와 beta 합이 1보다 크기 때문에 전체적으로 밝게 나온다 
																//5번째 인자는 gamma 값이다. 

	imshow("image1",	 image1);
	imshow("image2",	 image2);
	imshow("add_img1",	 add_img1);
	imshow("add_img2",   add_img2);
	imshow("add_img3",   add_img3);
	imshow("add_img4",   add_img4);
	
	waitKey();
	return 0;
}