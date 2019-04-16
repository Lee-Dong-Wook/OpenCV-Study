//���� ������ �о� �����쿡 ǥ��
//���콺 �̺�Ʈ�� ���� �巡�� �� �� ���õ� ������ �����Ǿ� ǥ�õǵ��� ���α׷� �ۼ� 

//���� 
//1. ������ �о� �����쿡 ǥ�� 
//2. ���콺 �̺�Ʈ ���. �巡��? ���콺 ��ư���� ��ǥ�� ��� �������� ������ ����� �簢���� �����. 
//   ���� �簢���� �׸����� ������ RectŬ���� ���, ���ɿ��� ���� �����̹����� ���ɿ��� ����
//3. ��Ʈ���� not�� �ؼ� �����ϱ� 

//abs(int n) ���밪 ���� �μ� n�� ���밪�� ����  

//imshow("name",image);
//"name"�̶�� �����쿡 image��� ����� ����. 
//"name"�̶�� �̸��� �ܼ��� �̸��� �ƴ϶� Ư�� �����츦 ��Ī�ϴ� �������� �����̴�. 

//opencv imshow(), setMouseCallback() reference 
//https://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html?highlight=setmousecallback
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

bool buttonDown = false;			//���콺 ���� ��ư Ŭ�� ���� 
bool buttonUp = false;

Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", 1);

Point click1, click2;

Rect box;

void reverseImage(Mat img);

static void mouse_callback(int event, int x, int y, int, void* param) {

	if (event == EVENT_LBUTTONDOWN) {			//������ �� 

		buttonDown = true;

		click1.x = x;							//Ŭ���� ��ǥ ���� 
		click1.y = y;

	}//EVENT_LBUTTONDOWN

	if (event == EVENT_LBUTTONUP) {				//������ �� 

		if (abs(x - click1.x) > 20 && abs(y - click1.y) > 20) {

			buttonUp = true;

			click2.x = x;
			click2.y = y;
		}

		else {
			buttonDown = false;
		}
	}//EVENT_LBUTTONUP

	if (buttonDown == true && buttonUp == false) {//�����϶� 

		Point pt;

		pt.x = x;
		pt.y = y;

		/*rectangle(image, click1, pt, Scalar(0, 255, 0));	//�Ź��� 

		imshow("Original IMG", image);*/

		Mat locale_img = image.clone();

		rectangle(locale_img, click1, pt, Scalar(0, 255, 0));

		imshow("Original IMG", locale_img);



	}//�����϶� 

	if (buttonDown == true && buttonUp == true) {

		box.width = abs(click1.x - click2.x);		//�簢�� ������ ������´�. 
		box.height = abs(click1.y - click2.y);

		box.x = min(click1.x, click2.x);
		box.y = min(click1.y, click2.y);
					
													//���⼭ �ڰ��� ������ �̹����� ������ ����� �ٽ� �����ϰ� ������Ų�� 
													//��â���� ���� ���� �簢�� ������ �����̹��� 
													//�����̹����� ������ �����ϸ� �����̹����� ��â�� �ߴ� ���̾ƴ϶� �����̹����� �ٷ� ����ǰ� �ؾ��Ѵ� 
		Mat bitNot(image, box);
		
		reverseImage(bitNot);

		
		buttonDown = false; buttonUp = false;
	}
}

void reverseImage(Mat img) {

	bitwise_not(img, img);							//������ �κ� ���� 
	imshow("Original IMG", image);					//����� �̹��� ��� 
}





int main() {

 
	CV_Assert(image.data);

	imshow("Original IMG", image);

	setMouseCallback("Original IMG", mouse_callback);

	

	waitKey(0);
	return 0;
}




