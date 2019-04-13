#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.3 행렬 가감 연산 통한 영상 밝기 변경 

//영상의 화소에 특정한 상수 값을 더하면 영상이 밝아진다.
//특정 상수 값을 빼면 영상이 어두어 진다. 
//또한 화소가 가질 수 있는 최댓값(255)에서 화소의 값을 빼면 반전 영상이 만들어 진다.

// ** 포화 산술 저장 saturate_cast ** 
//    오버플로우가 됬을 때 예로 254 + 2 = 256이지만 255를 넘어서 0으로 인식.
//    상식적으로 엄청 밝은 색으로 나와야하지만 오히려 검은색으로 나오게 되버린다.
//    그래서 최대값을 넘어서면 최대값으로 고정을 시켜버린다. 

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg",IMREAD_GRAYSCALE);
	CV_Assert(!image.empty());

	Mat dst1 = image + 100;		//밝게
	Mat dst2 = image - 100;		//어둡게
	Mat dst3 = 255 - image;		//반전

	Mat dst4(image.size(), image.type());	//이미지 크기, 이미지의 속성 그대로 
	Mat dst5(image.size(), image.type());	
	Mat dst6(image.size(), image.type());
	Mat dst7(image.size(), image.type());
	Mat dst8(image.size(), image.type());
	
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {

			dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i, j); //원소별 접근 영상 반전은 포화산술적용하지 않아도 된다. 

			dst4.at<uchar>(i, j) = image.at<uchar>(i, j) + 100;
			dst6.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) + 100);
			
			dst7.at<uchar>(i, j) = image.at<uchar>(i, j) - 100;
			dst8.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) - 100);
		}

		imshow("원본 영상 image",	image);
		imshow("dst1 +100 밝게 포화산술 자동적용",		dst1);		//행렬 연산시 자동으로 포화산술 연산 적용 
		imshow("dst2 -100 어둡게 포화산술 자동적용",	    dst2);      //행렬 연산시 자동으로 포화산술 연산 적용 
		imshow("dst3 영상반전",		dst3);
		imshow("dst5 영상반전",     dst5);
		imshow("dst4 +100 밝게 포화산술 미적용",		    dst4);		//원소별 연산시 포화 산술 연산 미적용 
		imshow("dst6 +100 밝게 포화산술 적용",           dst6);
		imshow("dst7 -100 어둡게 포화산술 미적용",       dst7);
		imshow("dst8 -100 어둡게 포화산술 적용",         dst8);
	}

	waitKey();
	return 0;
}