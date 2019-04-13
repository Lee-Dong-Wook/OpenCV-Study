#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.2 컬러 공간 변환(BGR->CMYK)

//컬러영상을 읽고 CMY 컬러공간으로 바꾸고 다시 CMYK 컬러 공간으로 변경 

//이전 예제 보다 영상이 어둡다. 각 채널 각 화소에서 가장 어두운 색을 검은 색으로 분리하여 black채널로 출력
//나머지 부분만을 각 색상의 잉크로 출력, CMYK 컬러 공간을 사용하면 컬러 잉크의 사용이 절감된다 

int main() {

	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Scalar white(255, 255, 255);
	Mat	   CMY_img = white - BGR_img;		//CMYK : 행렬 대 스칼라 뺄셈 -> 모든 채널의 모든 화소에 뺄셈을 적용 
	Mat    CMY_arr[3];

	split(CMY_img, CMY_arr);

	Mat black;
	min(CMY_arr[0], CMY_arr[1], black);			//원소 간 최솟값 저장, 여기서 BLACK은 검은 화면이 아니라 CMY의 최소값이다 
	min(black, CMY_arr[2], black);

	CMY_arr[0] = CMY_arr[0] - black;
	CMY_arr[1] = CMY_arr[1] - black;
	CMY_arr[2] = CMY_arr[2] - black;

	imshow("black", black);
	imshow("CMY_img[0] Y", CMY_arr[0]);		//yello
	imshow("CMY_img[1] M", CMY_arr[1]);		//magenta
	imshow("CMY_img[1] C", CMY_arr[2]);	    //cyan

	/*vector<Mat> vecY, vecM, vecC;
	Mat zero(BGR_img.size(), CV_8U, Scalar(0));

	vecY.push_back(CMY_arr[0]);
	vecY.push_back(zero);
	vecY.push_back(zero);

	vecM.push_back(zero);
	vecM.push_back(CMY_arr[1]);
	vecM.push_back(zero);

	vecC.push_back(zero);
	vecC.push_back(zero);
	vecC.push_back(CMY_arr[2]);

	Mat Y, M, C;

	merge(vecY, Y);
	merge(vecM, M);
	merge(vecC, C);

	imshow("C", Y);
	imshow("M", M);
	imshow("Y", C);*/

	
	

	


	waitKey();
	return 0;
}