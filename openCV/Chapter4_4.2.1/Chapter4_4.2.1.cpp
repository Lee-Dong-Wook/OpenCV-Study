#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	//4.2.1 키 이벤트 사용  

	Mat image(200, 300, CV_8U, Scalar(255));			//흰색 바탕 영상 생성, 1채널 uchar 행렬, 255로 초기화  
	
	namedWindow("키보드 이벤트", WINDOW_AUTOSIZE);				
	imshow("키보드 이벤트", image);						//"키보드 이벤트" 창에 행렬 영상으로 표시 

	while (1) {

		//int key = waitKey(100);							//100ms 대기하며 키입력 기다린다. 키입력이 없으면 -1반환 
		int key = waitKeyEx(0);    //100ms동안 키 입력이 들어오는것을 기다린다. 키 입력이 안들어왔을 경우 반복문에 의해 재 실행된다.   //아무 숫자나 들어와도 상관없다
						   //waitKey()를 사용하면 방향키 값이 0으로 반환된다. 대신 waitKeyEx()를 사용하면 전체 키값을 반환하기 때문에 방향키의 전체 키값을 switch문에 넣어주면 
						   //방향키를 제대로 입력받을 수 있다.

		if (key == 27) break;							//ESC 입력 

		switch (key) {

		case 'a'	: cout << " a 키 입력 " << endl; break;
		case 'b'	: cout << " b 키 입력 " << endl; break;
		case 0x41	: cout << " A 키 입력 " << endl; break;
		case 66		: cout << " B 키 입력 " << endl; break;
		
		case 0x250000 : cout << " 왼쪽 화살표 키 입력 " << endl; break;
		case 0x260000 : cout << " 윗쪽 화살표 키 입력 " << endl; break;
		case 0x270000 : cout << " 오른쪽 화살표 키 입력 " << endl; break;
		case 0x280000 : cout << " 아래쪽 화살표 키 입력 " << endl; break;
		
		}

	}
	
	return 0;
}

