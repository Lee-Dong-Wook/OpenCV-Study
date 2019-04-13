#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.1 컬러 공간변환(BGR -> CMY)

//RGB 컬러 공간 - 빛 
//빛의 삼원색 R(red) G(green) B(blue)
//더하면 더할 수록 밝아지는 가산 혼합 
//RGB 컬러 공간은 빛을 물리적으로 표현하고 만드는데 사용되는 기본 컬러 공간이다. 

//CMY(K) 컬러 공간 - 색 
//색의 삼원색 C(cyan)청록, M(Magenta)자홍, Y(Yello)
//더하면 더할 수록 탁해지는 감산 혼합 
//RGB의 역수, 빛의 삼원색과 보색관계

//C = 255 - R | R = 255 - C
//M = 255 - G | G = 255 - M 
//Y = 255 - R | B = 255 - Y

//C + M + Y 를 한다고 순수한 검은 색이 나오지는 않는다. 
//K(black)을 추가한다. 

//CMY 에서 CMYK 컬러 공간으로 바꾸는 수식 
//Black은 단순히 검정색이 아닌 CMY요소중 최소값(min)을 뜻한다 

// Black   = min(Cyan, Magetna, Yello)
// Cyan    = Cyan - balck 
// Magenta = Magenta - black
// Yello   = Yello - black 

//실행결과 
//CMY 컬러 공간의 영상은 RGB컬러 공간의 영상과 보수관계라 모니터에 출력하면 BGR_img를 반전한 것처럼 보인다.
//CMY_img를 단일 채널로 분리했기 때문에 각 채널은 Gray-Scale로 나온다
//
//만약 이 행렬들이 프린터로 출력된다면 검은 부분은 잉크가 출력되지 않고 밝은 색 부분이 화소값 비율만큼 각채널(C,M,Y)의 색으로 출력된다 


int main() {

	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Scalar white(255, 255, 255);
	Mat	   CMY_img = white - BGR_img;		//CMYK : 행렬 대 스칼라 뺄셈 -> 모든 채널의 모든 화소에 뺄셈을 적용 
	Mat    CMY_arr[3];

	split(CMY_img, CMY_arr);

	imshow("BGR_img", BGR_img);
	imshow("CMY_img", CMY_img);
	imshow("CMY_img[0] Y", CMY_arr[0]);		//yello
	imshow("CMY_img[1] M", CMY_arr[1]);		//magenta
	imshow("CMY_img[1] C", CMY_arr[2]);	    //cyan
	

	waitKey();
	return 0;
}