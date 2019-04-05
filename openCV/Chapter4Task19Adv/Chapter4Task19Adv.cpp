

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

//pc카메라를 통해서 영상을 입력, 좌우를 뒤집어서 flip_test.avi로 이름의 동영상 파일로 저장
//동영상 파일 크기 640 x 480
//초딩 프레임 수 : 15fps 
//동영상 코덱 : DIVX 

int main() {

	/*	1. 실시간으로 영상을 입력받는다.
		2. 영상, 코덱 종류, 프레임, 사이즈 모두 설정 후 , cmd로 출력한다.
		3. 저장한는 writer 객체 생성 후 설정
		4. while 문에서 영상 프레임 하나하나를 행렬로 capture 객체를 통해 받는다.
		5. flip함수를 통해 좌우 반전 시키키고
		6. writer.write(frame);
		7.비디오 저장 */

	VideoCapture capture(0);										//비디오객체 선언 및 0번 카메라 연결 
	CV_Assert(capture.isOpened());									//카메라 연결 예외 처리

	double fps = 15.0;												//초당 프레임 수 
	int	   delay = cvRound(1000.0 / fps);							//프레임간 지연시간 
	Size   size(320, 160);											//동영상 파일 해상도
	int	   fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');		//압축 코덱 설정

	capture.set(CAP_PROP_FRAME_WIDTH, size.width);					//해상도 설정(저장 해상도 지정) 
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);

	cout << "width x hieght : " << size << endl;
	cout << "VideoWriter::fourcc : " << fourcc << endl;			//동영상 정보 콘솔창 출력 
	cout << "delay : " << delay << endl;
	cout << "fps : " << fps << endl;

	VideoWriter writer;												//동영상 파일 저장 객체 
	writer.open("C:/Users/Raynor/Desktop/openCVEXImage/reverse2.avi", fourcc, fps, size); //파일 개방 및 설정 
	CV_Assert(writer.isOpened());

	while (true) {

		if (waitKey(delay) > 0) break;

		Mat frame, reverse;
		capture >> frame;											//카메라 영상받기 
		//flip(frame, reverse, 1);
		writer << reverse;											//프레임을 동영상으로 저장 


		imshow("카메라 영상보기", frame);

	}
	return 0;
}

//행렬 원소 접근 
//m1(1,2,3,4,5,6);
//m(0,0) = 1    m(0,1) = 2 

	/*int x = mat.rows;
	int y = mat.cols;
	Mat convert(x,y,CV_32FC3);
	convert = mat;*/

//Rect클래스 혹은 mat접근 방식으로 영상을 행렬로 받아온다. 
//각 행, 열의 값을 파악한다. 
//좌우반전이니까 행은 변경하지 않고 열만 변경한다. 1행의 모든 열이 1,2,3,4,5,6,7,8,9 이면 
//출력은 9,8,7,6,5,4,3,2,1 로 출력하게 한다. 
//2중 for문을 돌리는데 첫번째 for문은 행에 대해서 2번째 for문을 열에대해서 돌린다. 
