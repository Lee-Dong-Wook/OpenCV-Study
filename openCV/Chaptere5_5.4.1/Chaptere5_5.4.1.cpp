#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.4.1 행렬 절댓값 및 차분 연산 (예제의 결과가 책과 다르다 다시확인해볼필요가 있음)
//차분 값 : 앞 - 뒤 = 결과값 

//이미지의 사이즈(해상도)가 같지 않을 경우 다음과 같은 에러가 발생 
//OpenCV(4.0.1) Error: Sizes of input arguments do not match 
//(The operation is neither 'array op array' 
//(where arrays have the same size and the same number of channels), 
//nor 'array op scalar', nor 'scalar op array') in cv::arithm_op, 
//file c:\build\master_winpack-build-win64-vc15\opencv\modules\core\src\arithm.cpp, line 663

//MatExpr abs() 행렬의 각 원소에 대한 절대값을 계산하여 수식을 위한 행렬인 MatExpr객체에 반환
//void    absdiff() 두배열간 각 원소 간 차분의 절대값을 계산 src1,src2 중 하나는 스칼라 값이 될 수 있다. 
int main() {

	Mat image1 = imread("C:/Users/Raynor/Desktop/openCVEXImage/image4.jpg", 0);			// 값 0은 명암도 영상 로드
	Mat image2 = imread("C:/Users/Raynor/Desktop/openCVEXImage/image5.jpg", 0);
	CV_Assert(image1.data && image2.data);												//예외 처리 

	Mat dif_img, abs_dif1, abs_dif2;

	image1.convertTo(image1, CV_16S);													//행렬 형 변환(uchar -> short)
	image2.convertTo(image2, CV_16S);

	subtract(image1, image2, dif_img);													//뺄셈 수행 

	Rect roi(10, 10, 7, 3);
	cout << "[dif_img] = " << endl << dif_img(roi) << endl;

	abs_dif1 = abs(dif_img);

	image1.convertTo(image1, CV_8U);													//행렬 형 변환(short -> uchar)
	image2.convertTo(image2, CV_8U);
	dif_img.convertTo(dif_img,CV_8U);
	abs_dif1.convertTo(abs_dif1,CV_8U);

	absdiff(image1, image2, abs_dif2);													//차분 절댓값 계산 

	cout << "[dif_img] = " << endl << dif_img(roi) << endl << endl;
	cout << "[abs_dif1] = " << endl << abs_dif1(roi) << endl << endl;
	cout << "[abs_dif2] = " << endl << abs_dif2(roi) << endl << endl;

	imshow("image1", image1);
	imshow("image2", image2);
	imshow("dif_img", dif_img);
	imshow("abs_dif1", abs_dif1);
	imshow("abs_dif2", abs_dif2);

	waitKey();
	
	return 0;
}

