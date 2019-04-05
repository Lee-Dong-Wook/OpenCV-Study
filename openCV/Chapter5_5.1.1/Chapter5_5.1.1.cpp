#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.1.1 행렬처리함수 
//이미지 -> 행렬 -> 처리 
//RGB각각 분리 및 처리. 속성을 한가지로만 뽑을 때 Grayscale로 처리 된다. 
//컴퓨터는 RGB가 아닌 BGR 순서로 처리 된다. 
//R,G,B 3개의 정보는 각각 2차원 행렬 정보 -> 2차원 행렬 정보 x 3, 즉 3차원 배열이 된다. 


int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg",IMREAD_COLOR);
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img; 
	flip(image, x_axis, 0);									//x축 기준 상하 뒤집기
	flip(image, y_axis, 1);									//y축 기준 좌우 뒤집기 
	flip(image, xy_axis,-1);

	repeat(image,1,2,rep_img);								//반복 복사 
	transpose(image,trans_img);								//행렬 전치 

	imshow("image", image);
	imshow("x_axis", x_axis);
	imshow("y_axis", y_axis);
	imshow("xy_axis", xy_axis);
	imshow("rep_img", rep_img);
	imshow("trans_img", trans_img);

	waitKey();
	return 0;


}

