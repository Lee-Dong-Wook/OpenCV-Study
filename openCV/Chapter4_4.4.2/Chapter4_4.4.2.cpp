#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.2 행렬을 영상 파일로 저장 

//cv::imwrite() 사용
//jpg,bmp,png,tif 등 영상 파일 포맷 저장 가능 
//params 벡터로 jpg 파일의 화질이나 png파일의 압축률도 설정 가능
//
//paramValue(default value)
//IMWRITE_JPEG_QUALITY		0~100(95)
//IMWRITE_PNG_COMPRESSION	0~9(3)
//IMWRITE_PXM_BINARY		0 or 1(1)
//
//IMWRITE_JPEG_QUALITY		jpg파일화질, 높은 값일 수록 화질이 좋다
//IMWRITE_PNG_COMPRESSION	png 파일 압축레벨, 높은 값일 수록 적은 용량, 긴 압축 시간
//IMWRITE_PXM_BINARY		PPM, PGM 파일의 이진 포맷 설정 


int main() {

	Mat img8 = imread("C:/Users/Raynor/Desktop/openCVEXImage/image3.jpg",IMREAD_COLOR);	//파일을 그대로 가지고 오는 것이 아닌
																						//파일을 가지고와 행렬로 저장 
	
	CV_Assert(img8.data);

	vector<int> params_jpg, params_png;

	params_jpg.push_back(IMWRITE_JPEG_QUALITY);											//영상 파일 저장, jpg 화질 설정 
	params_jpg.push_back(50);															//100이 최고화질
																						
	params_png.push_back(IMWRITE_PNG_COMPRESSION);										//png 압축 렐벨 설정 
	params_png.push_back(9);															//9가 최고압축률 

	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test1.jpg",img8);				//행렬 영상파일로 저장 
	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test2.jpg", img8,params_jpg);  //지정화질로 저장 
	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test3.png", img8, params_png);
	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test4.bmp", img8);				//bmp 파일 저장 

	waitKey(0);
	return 0;
}

