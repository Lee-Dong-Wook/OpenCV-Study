//영상 파일을 읽어 윈도우에 표시
//마우스 이벤트를 통해 드래그 할 때 선택된 영역이 반전되어 표시되도록 프로그램 작성 

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

void reverseImage(Mat img);

static void mouse_callback(int event, int x, int y, int, void* param) {

	if (event == EVENT_LBUTTONDOWN) {			//눌렀을 때 

		buttonDown = true;

		click1.x = x;							//클릭한 좌표 설정 
		click1.y = y;

	}//EVENT_LBUTTONDOWN

	if (event == EVENT_LBUTTONUP) {				//떼었을 때 

		if (abs(x - click1.x) > 20 && abs(y - click1.y) > 20) {

			buttonUp = true;

			click2.x = x;
			click2.y = y;
		}

		else {
			buttonDown = false;
		}
	}//EVENT_LBUTTONUP

	if (buttonDown == true && buttonUp == false) {//움직일때 

		Point pt;

		pt.x = x;
		pt.y = y;

		/*rectangle(image, click1, pt, Scalar(0, 255, 0));	//신박함 

		imshow("Original IMG", image);*/

		Mat locale_img = image.clone();

		rectangle(locale_img, click1, pt, Scalar(0, 255, 0));

		imshow("Original IMG", locale_img);



	}//움직일때 

	if (buttonDown == true && buttonUp == true) {

		box.width = abs(click1.x - click2.x);		//사각형 범위를 가지고온다. 
		box.height = abs(click1.y - click2.y);

		box.x = min(click1.x, click2.x);
		box.y = min(click1.y, click2.y);
					
													//여기서 자각형 범위와 이미지를 가지는 행렬을 다시 선언하고 반전시킨다 
													//새창으로 띄우는 것은 사각형 범위의 원본이미지 
													//원본이미지에 범위를 지정하면 반전이미지가 새창에 뜨는 것이아니라 원본이미지에 바로 적용되게 해야한다 
		Mat bitNot(image, box);
		
		reverseImage(bitNot);

		
		buttonDown = false; buttonUp = false;
	}
}

void reverseImage(Mat img) {

	bitwise_not(img, img);							//선택한 부분 반전 
	imshow("Original IMG", image);					//변경된 이미지 출력 
}





int main() {

 
	CV_Assert(image.data);

	imshow("Original IMG", image);

	setMouseCallback("Original IMG", mouse_callback);

	

	waitKey(0);
	return 0;
}




