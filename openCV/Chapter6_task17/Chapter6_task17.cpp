//영상 파일을 읽어 윈도우에 표시
//마우스 이벤트를 통해 드래그 할 때 선택된 영역이 반전되어 표시되도록 프로그램 작성 

  //void calcHist(const Mat *image,		원본영상 배열 - CV_8U or CV_32F 형으로 크기가 같아야함
		//		  int nimage,			원본영상 개수 
		//		  const int *channels,  히스토그램 계산에 사용되는 차원 목록 
		//		  InputArray mask,      특정 영역만 계산하기 위한 마스크 행렬 - 입력 영상과 같은 크기의 8비트 배열 
		//		  OutputArray hist,     계산된 히스토그램이 출력되는 배열 
		//		  int dims,				히스토그램의 차원 수 
		//		  const int *histSize,	각 차원의 히스토그램 배열 크기 - 계급(bin)의 개수 
		//		  float **ranges,       각 차원의 히스토그램 범위 
		//		  bool uniform,			히스토그램이 균일(uniform)한지를 나타내는 플래그
		//		  bool accumulate);		누적플래그 - 여러 배열에서 단일 히스토그램을 구할 때 사용 

//구현 
//1. 영상을 읽어 윈도우에 표시 
//2. 마우스 이벤트 사용. 드래그? 마우스 버튼으로 좌표를 찍어 시작점과 끝점을 만들어 사각형을 만든다. 
//   영상에 사각형을 그리지는 않지만 Rect클래스 사용, 관심영역 만들어서 원본이미지의 관심영역 저장
//3. 비트연산 not을 해서 반전하기 

//abs(int n) 절대값 정수 인수 n의 절대값을 리턴  

//imshow("name",image);
//"name"이라는 윈도우에 image라는 행렬을 띄운다. 
//"name"이라는 이름은 단순한 이름이 아니라 특정 윈도우를 지칭하는 변수명같은 존재이다. 

//opencv imshow(), setMouseCallback() reference 
//https://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html?highlight=setmousecallback
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

bool buttonDown = false;			//마우스 왼쪽 버튼 클릭 여부 
bool buttonUp = false;

Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", 1);

Point click1, click2;

Rect box;

void reverseImage(Mat img);													//전방선언에서는 매개변수 초기화가 안된다. 
void calc_Histo(const Mat& image, Mat &hist, int bins, int range_max);
Mat make_palatte(int rows);
void draw_histo_hue(Mat hist, Mat &hist_img, Size size );
void printHisto();

static void mouse_callback(int event, int x, int y, int, void* param) {

	if (event == EVENT_LBUTTONDOWN) {			//눌렀을 때 

		buttonDown = true;

		click1.x = x;							//마우스 클릭한 좌표 설정 - click1좌표
		click1.y = y;

	}//EVENT_LBUTTONDOWN

	if (buttonDown == true && buttonUp == false) { //MouseMoving 움직일때, 버튼은 눌러져있다

		Point pt;

		pt.x = x;
		pt.y = y;

		/*rectangle(image, click1, pt, Scalar(0, 255, 0));	//신박함

		imshow("Original IMG", image);*/

		Mat locale_img = image.clone();

		rectangle(locale_img, click1, pt, Scalar(0, 255, 0));	//사각형 그리기. 	
																//시작위치 = click1, 시작위치를 떠나 마우스가 계속움직이면서 있던 위치
																
		imshow("Original IMG", locale_img);



	}//MouseMoving 

	if (buttonDown == true && buttonUp == true) {	//boxArea_bitnot

		box.width = abs(click1.x - click2.x);		//사각형 범위를 가지고온다. 
		box.height = abs(click1.y - click2.y);

		box.x = min(click1.x, click2.x);
		box.y = min(click1.y, click2.y);

		Mat bitNot(image, box);						//여기서 자각형 범위와 이미지를 가지는 행렬을 다시 선언하고 반전시킨다 
													
		reverseImage(bitNot);						//원본이미지에 범위를 지정하면 반전이미지가 새창에 뜨는 것이아니라 원본이미지에 바로 적용되게 해야한다 

		printHisto();

		buttonDown = false; buttonUp = false;
	}//boxArea_bitnot

	if (event == EVENT_LBUTTONUP) {				//떼었을 때 

		if (abs(x - click1.x) > 1 && abs(y - click1.y) > 1) {	//거의 항상 True, 
																//절댓값을 쓰는 이유는 시작위치보다 두번째 위치가 작을 때 음수가 나오는 것을 방지 

			buttonUp = true;

			click2.x = x;						//마우스 클릭을 떼었을 때 좌표 설정 - click2좌표		
			click2.y = y;						//MouseMoving이 끝나자마자 click2 지점이 고정
												////boxArea_bitnot로 조건이동하여 이미지 반전 
		}

		else {									//다른 기능 추가할 때 사용 				
			buttonDown = false;					//굳이 없어도 작동되지만 구조적 문제에 의해 에러발생 방지 
		}
	}//EVENT_LBUTTONUP
}

void reverseImage(Mat img) {

	imshow("choosed Img", img);						//선택 구역에대해서 윈도우 출력 

	bitwise_not(img, img);							//선택한 부분 반전 

	imshow("Original IMG", image);
}



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
  
Mat make_palatte(int rows) {										//hue 채널에 대한 색상 팔레트 행렬 생성 

	Mat hsv(rows, 1, CV_8UC3);										//색상 팔레트 행렬 선언, 색상, 채도, 휘도를 갖도록 3채널 

	for (int i = 0; i < rows; i++) {								//행 수만큼 반복 

		uchar hue = saturate_cast<uchar>((float)i / rows * 180);	//색상 계산, 계급의 인덱스(i)을 hue값으로 계산 * hue는 0~180까지 값을 가짐 *
		hsv.at<Vec3b>(i) = Vec3b(hue, 255, 255);					//HSV 컬러 지정 , 3채널 화소값 지정 
	}

	cvtColor(hsv, hsv, COLOR_HSV2BGR);								//HSV 컬러 -> BGR 컬러
																	//설정은 HSV로 하지만 모니터에 표시하기 위해선 BGR로 표시 
	return hsv;
}

//색상으로 히스토 그램 그리기
void draw_histo_hue(Mat hist, Mat &hist_img, Size size = Size(256, 200)) {

	Mat hsv_palatte = make_palatte(hist.rows);						//색상 팔레트 생성 make_palatte()함수로 막대그래프의 각 계급 색상을 행렬로 반환 

	hist_img = Mat(size, CV_8UC3, Scalar(255, 255, 255));
	float bin = (float)hist_img.cols / hist.rows;					//계급 개수,한 계급의 너비 256/200 = 1.28
	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);			//최솟값이 0, 최댓값이 그래프 영상의 높이(hist_img.rows)값을 갖도록 히스토그램 빈도값 조정

	for (int i = 0; i < hist.rows; i++) {

		float start_x = (i * bin);
		float end_x = (i + 1) * bin;

		Point2f pt1(start_x, 0);
		Point2f pt2(end_x, hist.at<float>(i));

		Scalar color = hsv_palatte.at<Vec3b>(i);					//색상 팔레트 색지정 

		if (pt2.y > 0) rectangle(hist_img, pt1, pt2, color, -1);	//팔레트 색으로 그리기 
	}

	flip(hist_img, hist_img, 0);									//상하 뒤집기 	
}

void printHisto() {

	Mat HSV_img, HSV_arr[3];
	cvtColor(image, HSV_img, COLOR_BGR2HSV);									//Hue에 대한 히스토그램 계산을 위해 BGR 컬러 -> HSV 컬러 
	split(HSV_img, HSV_arr);													//HSV_img 행렬 채널 분리 
																				//[0] Hue(색상), [1] Saturation(채도), [2] Value(명도)	

	Mat hue_hist, hue_hist_img;
	calc_Histo(HSV_arr[0], hue_hist, 18, 180);									//Hue 채널 히스토그램 계산
																				//계급 개수는 18개 빨~보, 0~179까지 범위에 대해 빈도 계산

	draw_histo_hue(hue_hist, hue_hist_img, Size(360, 200));						//히스토그램 그래프 


	imshow("Hue_hist_img", hue_hist_img);
}

int main() {

	CV_Assert(image.data);

	imshow("Original IMG", image);
	//imshow("Original IMG", image);				//반복작성해도 동일한 윈도우창이기 때문에 하나만 출력된다. 

	setMouseCallback("Original IMG", mouse_callback);

	
	waitKey(0);
	return 0;
}




