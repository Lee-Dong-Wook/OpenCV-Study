#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.1 명암도 영상 생성 

//흑백영상				= Binary image 0,1로 이루어진 흰색,검은색화면 
//루미넌스, 그레이스케일  = Gray scale, 0~255값을 가지는 화소, 단일채널 영상을, 명암도, 회색조 영상이라 부름 

int main() {

	Mat image1(50, 512, CV_8UC1, Scalar(0));		//50행 512열, 50x512 영상 
	Mat image2(50, 512, CV_8UC1, Scalar(0));

	for (int i = 0; i < image1.rows; i++) {			//행렬 전체 순회 
		for (int j = 0; j < image1.cols; j++) {

			image1.at<uchar>(i, j) = j/2;			//image 열이 512이기 때문에 255가지 색을 모두 넣으려면 2를 나누어야한다. 
			image2.at<uchar>(i, j) = (j / 20) * 10; //계단현상 
		}
	}

	imshow("image1", image1);
	imshow("image2", image2);

	waitKey();

	return 0;
}