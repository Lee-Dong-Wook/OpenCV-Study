#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


//임의 영상 파일을 행렬로 읽어 들여서 예외처리, 그정보들을 xml파일로 저장
//1) 영상크기를 image_size라는 이름으로 저장
//2) 영상의 깊이 값(depth)라는 이름으로 저장
//3) 영상의 모든 화소값들을 image_data로 저장 

int main() {

	Mat mat = imread("C:/Users/Raynor/Desktop/openCVEXImage/mine1.jpg", IMREAD_UNCHANGED);
	CV_Assert(mat.data);	//영상파일 예외 처리
	FileStorage fs("test.xml", FileStorage::WRITE);



	fs << "image_size" << mat.size();				//이미지 해상도  
	fs << "depth" << mat.depth();					//이미지 깊이 
	
	fs << "mat" << "[";
	fs << "image_data " << mat;						//이미지 행렬 
	fs << "]";
	fs.release();

	return 0;
}








