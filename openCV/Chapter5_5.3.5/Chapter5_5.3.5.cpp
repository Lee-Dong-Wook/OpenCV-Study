#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.5 행렬 비트연산 
//컬러 영상을 오버랩하기 위해서 logo 영상을 먼저 각 채널로 분리하여 이진화를 수행.
//이진화는 cv::threshold() 사용 

//Error with OpenCV ROI
//Assertion failed 
//(0 <= roi.x && 0 <= roi.width && roi.x + roi.width <= m.cols && 0 <= roi.y && 0 <= roi.height && roi.y + roi.height <= m.rows)
//예외처리로 이러한 에러가 발생할 수 있는데 삽입하는 로고의 크기가 image보다 더 클 경우 다음과 같은 에러가 발생한다. 

//0은 balck , black 이외의 모든 색상은 1 
//0 = false, 1 = true 

//threshold(logo, logo_th, 70, 255, THRESH_BINARY_INV);		
//bitwise_and(masks[0], masks[1], masks[3]);
//다른 결과가 나온다. 
int main() {
	Mat image	= imread("C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg", IMREAD_COLOR);
	Mat logo	= imread("C:/Users/Raynor/Desktop/openCVEXImage/opencvLogo.png", IMREAD_COLOR);
	Mat logo_th, masks[5], background, foreground, dst;											
	
	CV_Assert(image.data && logo.data);															//예외 처리 
	
	threshold(logo, logo_th, 70, 255, THRESH_BINARY);											//로고 영상 이진화 
	//threshold()로 이진화 수행. THRESH_BINAR옵션은 기준값 70보다 작은 화소는 0으로 큰화소는 255로 만든다. 
	//로고에서 빨,파,초,흰 요소 모두 흰색으로 배경 검은색은 검은색으로 
	//logo를 입력하여 이진화 시켜 logo_th에 출력 
	imshow("raw_image", image);
	imshow("raw_logo", logo);
	imshow("logo_th", logo_th);
	split(logo_th, masks);																//logo_th행렬을 1채널 행렬, 3개를 갖는 배열로 분리

	bitwise_or(masks[0], masks[1], masks[3]);													//전경 통과 마스크 //(입력, 입력, 출력) 	
	bitwise_or(masks[2], masks[3], masks[3]);
	//분리된 3개 masks행령를 bitwise_or()로 하나로 합쳐 masks[3]에 저장 
	//컬러 영상의 각 채널에서 70보다 큰 값을 갖는 부분만 흰색으로 만들어 전경 통과 마스크를 생성 
	
	imshow("masks[0]", masks[0]);
	imshow("masks[1]", masks[1]);
	imshow("masks[2]", masks[2]);

	bitwise_not(masks[3], masks[4]);														    //배경통과 마스크 
	//masks[3]를 반전해서 배경통과 마스크 masks[4]생성 
	imshow("masks[3]", masks[3]);
	imshow("masks[4]", masks[4]);

	Point center1	= image.size() / 2;															//영상 중심 좌표 				
	Point center2	= logo.size() / 2;															//로고 중심좌표 		
	Point start		= center1 - center2;
	Rect roi(start, logo.size());																//로고가 위치할 관심영역 

	//행렬 논리 곱과 마스킹을 이용한 관심영역 복사 
	bitwise_and(logo,logo, foreground, masks[3]);												//로고 전경 복사 
	//비트 논릴곱 수행, 두개의 입력 행렬을 같은 행렬로 지정하면 출력 행렬은 입력 행렬을 복사 
	//단, 마스크 행렬의 원소가 0이 아닌 위치만 복사 
	//masks[3]행렬의 전경이 255이기 때문에 로고의 전경 부분만 foreground 행렬에 복사 

	bitwise_and(image(roi), image(roi), background, masks[4]);									//원본의 배경 복사 
	//같은 방법으로 image행려의 관심영역을 두개의 입력하여 논리곱을 수행 
	//masks[4]행렬(배경 통과마스크)를 마스킹, image의 관심영역에서 배경 부분을 background행렬에 복사 

	add(background, foreground, dst);															//로고 전경과 원본 배경의 합성 
	dst.copyTo(image(roi));																		//합성 영상을 image 관심영역에 복사 
	//완성된 dst 행렬을 image행렬의 관심영역(roi)에 복사 

	imshow("background", background);
	imshow("foreground", foreground);
	imshow("dst",		 dst);
	imshow("image",		image);
	
	waitKey();
	return 0;
}

