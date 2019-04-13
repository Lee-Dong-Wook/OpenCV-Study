#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.2 영상 화소값 확인 

//파일을 읽어 관심영역을 정한 뒤 그 부분의 화소 값을 확인한다. 

int main() {

	//640 x 640 영상 200, 320쯤이 얼굴인듯 
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg", IMREAD_GRAYSCALE);

	if (image.empty()) {

		cout << "영상을 읽지 못했습니다." << endl; 
		exit(1);
	}

	Rect roi1(280, 120, 200, 200);			//관심영역 사각형, 사각형의 시작좌표 x, y, 사각형의 너비, 높이 
	Rect roi2(280, 120, 20, 20);
	Mat roi_img1 = image(roi1);			//관심영역 참조된 영상
	Mat roi_img2 = image(roi2);
	cout << "[roi_img] = " << endl; 

	//cout << image << endl;					  //영상 행렬 원소 모두 출력 - 과부화
	//cout << roi_img << endl;					  //관심 영역 행렬 원소 모두 출력 - 느림 

	for (int i = 0; i < roi_img2.rows; i++) {	 //관심 영역 행렬 원소 모두 출력 - 느림 
		for (int j = 0; j < roi_img2.cols; j++) {

			cout.width(5);                        //출력 원소 너비 지정 
			cout << (int)roi_img2.at<uchar>(i, j); //행렬 원소 모두 출력 
												  //uchar형으로 출력하기 때문에 문자나 특수문자들이 출력되므로 int로 형변환 							
		}
		cout << endl; 
	}
	imshow(" roi_image1 관심영역 부분 ", roi_img1);
	imshow(" roi_image2 관심영역 부분 ", roi_img2);

	rectangle(image, roi1, Scalar(255), 1);			//관심영역 부분을 사각형으로 그림 

	imshow("image", image); 

	waitKey();
	return 0;
}