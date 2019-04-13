#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.5 ��� ��Ʈ���� 
//�÷� ������ �������ϱ� ���ؼ� logo ������ ���� �� ä�η� �и��Ͽ� ����ȭ�� ����.
//����ȭ�� cv::threshold() ��� 

//Error with OpenCV ROI
//Assertion failed 
//(0 <= roi.x && 0 <= roi.width && roi.x + roi.width <= m.cols && 0 <= roi.y && 0 <= roi.height && roi.y + roi.height <= m.rows)
//����ó���� �̷��� ������ �߻��� �� �ִµ� �����ϴ� �ΰ��� ũ�Ⱑ image���� �� Ŭ ��� ������ ���� ������ �߻��Ѵ�. 

//0�� balck , black �̿��� ��� ������ 1 
//0 = false, 1 = true 

//threshold(logo, logo_th, 70, 255, THRESH_BINARY_INV);		
//bitwise_and(masks[0], masks[1], masks[3]);
//�ٸ� ����� ���´�. 
int main() {
	Mat image	= imread("C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg", IMREAD_COLOR);
	Mat logo	= imread("C:/Users/Raynor/Desktop/openCVEXImage/opencvLogo.png", IMREAD_COLOR);
	Mat logo_th, masks[5], background, foreground, dst;											
	
	CV_Assert(image.data && logo.data);															//���� ó�� 
	
	threshold(logo, logo_th, 70, 255, THRESH_BINARY);											//�ΰ� ���� ����ȭ 
	//threshold()�� ����ȭ ����. THRESH_BINAR�ɼ��� ���ذ� 70���� ���� ȭ�Ҵ� 0���� ūȭ�Ҵ� 255�� �����. 
	//�ΰ��� ��,��,��,�� ��� ��� ������� ��� �������� ���������� 
	//logo�� �Է��Ͽ� ����ȭ ���� logo_th�� ��� 
	imshow("raw_image", image);
	imshow("raw_logo", logo);
	imshow("logo_th", logo_th);
	split(logo_th, masks);																//logo_th����� 1ä�� ���, 3���� ���� �迭�� �и�

	bitwise_or(masks[0], masks[1], masks[3]);													//���� ��� ����ũ //(�Է�, �Է�, ���) 	
	bitwise_or(masks[2], masks[3], masks[3]);
	//�и��� 3�� masks��ɸ� bitwise_or()�� �ϳ��� ���� masks[3]�� ���� 
	//�÷� ������ �� ä�ο��� 70���� ū ���� ���� �κи� ������� ����� ���� ��� ����ũ�� ���� 
	
	imshow("masks[0]", masks[0]);
	imshow("masks[1]", masks[1]);
	imshow("masks[2]", masks[2]);

	bitwise_not(masks[3], masks[4]);														    //������ ����ũ 
	//masks[3]�� �����ؼ� ������ ����ũ masks[4]���� 
	imshow("masks[3]", masks[3]);
	imshow("masks[4]", masks[4]);

	Point center1	= image.size() / 2;															//���� �߽� ��ǥ 				
	Point center2	= logo.size() / 2;															//�ΰ� �߽���ǥ 		
	Point start		= center1 - center2;
	Rect roi(start, logo.size());																//�ΰ� ��ġ�� ���ɿ��� 

	//��� �� ���� ����ŷ�� �̿��� ���ɿ��� ���� 
	bitwise_and(logo,logo, foreground, masks[3]);												//�ΰ� ���� ���� 
	//��Ʈ ���� ����, �ΰ��� �Է� ����� ���� ��ķ� �����ϸ� ��� ����� �Է� ����� ���� 
	//��, ����ũ ����� ���Ұ� 0�� �ƴ� ��ġ�� ���� 
	//masks[3]����� ������ 255�̱� ������ �ΰ��� ���� �κи� foreground ��Ŀ� ���� 

	bitwise_and(image(roi), image(roi), background, masks[4]);									//������ ��� ���� 
	//���� ������� image����� ���ɿ����� �ΰ��� �Է��Ͽ� ������ ���� 
	//masks[4]���(��� �������ũ)�� ����ŷ, image�� ���ɿ������� ��� �κ��� background��Ŀ� ���� 

	add(background, foreground, dst);															//�ΰ� ����� ���� ����� �ռ� 
	dst.copyTo(image(roi));																		//�ռ� ������ image ���ɿ����� ���� 
	//�ϼ��� dst ����� image����� ���ɿ���(roi)�� ���� 

	imshow("background", background);
	imshow("foreground", foreground);
	imshow("dst",		 dst);
	imshow("image",		image);
	
	waitKey();
	return 0;
}

