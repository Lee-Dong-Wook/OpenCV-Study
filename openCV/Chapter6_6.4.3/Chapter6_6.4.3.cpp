#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.3 컬러 공간 변환(BGR -> HSI)

//색상(Hue), 채도(Saturation), 명도(Intensity value)
//색상은 원판의 0~360도까지 회전하며 표현 

//채도는 색의 순수한 정도, 순색(pure color)에 흰색의 혼합 비율에 따라 0~100까지 값
//컬러 공간에서는 채도는 원판의 반지름으로 표현, 원판의 중심이 0(가장 순도 낮음), 가장 자리가 100(가장 순도 높음)

//명도는 빛의 세기, 색의 밝고 어두운 정도 
//컬러 공간에서는 원뿔의 높이, 가장 아래가 0(Black), 가장 위가 100(White) 

//아래 예시는 직접 HSI로 변경한 경우와 cv::cvtColor()를 사용한 경우를 비교한다 

//실행결과 
//사용자 구현함수와 cvtColor()에는 거의비슷하지만 공식을 적용한 것은 영상의 크기만큼 2중 for문을 반복하여 
//acos() 함수등을 수행하기 때문에 크기가 큰 영상에 수행하면 상대적으로 많은 시간이 소요된다. 


void bgr2hsi(Mat img, Mat &hsi) {				//BGR 컬러 -> HSI 컬러 

	hsi = Mat(img.size(), CV_32FC3);			//HSI 행렬 - 3채널, float형 
	
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			float B = img.at<Vec3b>(i, j)[0];	
			float G = img.at<Vec3b>(i, j)[1];
			float R = img.at<Vec3b>(i, j)[2];

			float s = 1 - 3 * min(R, min(G, B)) / (R + B + G);		//채도 계산 
			float v = (R + G + B) / 3.0f;							//명도 계산 

			float tmp1  = ((R - G) + (R - B)) + 0.5f;
			float tmp2  = sqrt((R - G)*(R - B) + (G - B)*(G - B));
			float angle = acos(tmp1 / tmp2) * (180.0f / CV_PI);		//acos()는 역코사인을 구해주는 함수로 라디안 값을 변화하기 때문에 
																	//180 / CV_PI를 곱해도 각도로 변환한다 
			
			float h = (B <= G) ? angle : 360 - angle;				//색상 계산 
					
								//3채널 float행렬저장 ,0~1 범위값을 0~255로 저장 
			hsi.at<Vec3f>(i, j) = Vec3f(h / 2, s * 255, v);			//반환행렬 원소에 지정 
																	//계산된 h,s,v 값을 반환행렬에 저장, Hue 채널은 0~360도를 갖는데,
																	//uchar형이 0~255의 범위기에 절반으로 스케일해서 0~180 범위로 변경
																	//s 변수는 0~1의 값을 갖기에 255를 곱해서 0~255범위를 갖게 한다. 	
		}
	}
	hsi.convertTo(hsi, CV_8U);
}

int main() {

	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Mat HSI_img, HSV_img, hsi[3], hsv[3];

	bgr2hsi(BGR_img, HSI_img);								//BGR -> HSI 변환 
	cvtColor(BGR_img, HSV_img, COLOR_BGR2HSV);				//OPENCV 함수 

	split(HSI_img, hsi);
	split(HSV_img, hsv);


	imshow("BGR_img",			BGR_img);
	imshow("Hue",				hsi[0]);
	imshow("Saturation",		hsi[1]);
	imshow("Intensity",			hsi[2]);
	imshow("openCV Hue",		hsv[0]);
	imshow("openCV Saturation", hsv[1]);
	imshow("openCV Intensity",	hsv[2]);
	
	waitKey();
	return 0;
}