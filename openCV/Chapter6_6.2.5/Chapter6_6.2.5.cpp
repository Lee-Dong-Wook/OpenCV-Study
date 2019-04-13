#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.5 영상 대비 변경 

//명암대비(constrast)는 상이한 두가지 색(밝기)이 경계에서 서로 영향을 미쳐 그 차이가 강조되어 나타나는 현상
//낮은 명암대비의 영상은 밝은 부분과 어두운 부분의 차이가 크지 않아 전체적으로 어둡거나 밝다
//높은 명암 대비의 영상은 밝은 부분과 어두운 부분의 차이가 큰 영상 -> 전체적으로 영상이 또렷해보인다

//명암대비를 높이려면 어두운 부분은 더 어둡게 밝은 부분은 더밝게 해야한다.
//반대로 대비를 낮추려면 어두운 부분과 밝은 부분의 차이를 줄인다. 

//차이를 늘리거나 줄이는 방법은 곱셈 연상을 수행
//대비를 늘리려면 1.0이상 값을 곱하고 줄이려면 1.0이하 값을 곱한다. 

int main() {
 
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg",0);	//회색조 영상읽기 
	CV_Assert(image.data);

	Scalar avg = mean(image) / 2.0;		//원본 영상 화소 평균의 절반 
										//반환결과는 Scalar형으로 4개의 원소를 가지마 image가 1채널 행렬이라 0번 원소만 값을 갖는다
										//그래서 아래의 avg도 avg[0]으로 표기. 하지만 avg도 같은 결과를 가진다. 
	Mat dst1 = image * 0.5;				//명암대비 감소
	Mat dst2 = image * 2.0;				//명암대비 증가
	Mat dst3 = image * 0.5 + avg[0];	//영상 평균 이용 대비 감소 
	Mat dst4 = image * 2.0 - avg[0];	//영상 평균 이용 대비 증가 

	imshow("image", image);
	imshow("dst1-대비감소",			 dst1);
	imshow("dst2-대비증가",			 dst2);
	imshow("dst3-평균이용 대비감소",	 dst3);	// 평균을 이용하면 자연스럽고 선명하다 
	imshow("dst4-평균이용 대비증가",	 dst4);

	waitKey();
	return 0;
}