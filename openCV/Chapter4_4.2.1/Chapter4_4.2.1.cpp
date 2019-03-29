#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	//4.2.1 Ű �̺�Ʈ ���  

	Mat image(200, 300, CV_8U, Scalar(255));			//��� ���� ���� ����, 1ä�� uchar ���, 255�� �ʱ�ȭ  
	
	namedWindow("Ű���� �̺�Ʈ", WINDOW_AUTOSIZE);				
	imshow("Ű���� �̺�Ʈ", image);						//"Ű���� �̺�Ʈ" â�� ��� �������� ǥ�� 

	while (1) {

		//int key = waitKey(100);							//100ms ����ϸ� Ű�Է� ��ٸ���. Ű�Է��� ������ -1��ȯ 
		int key = waitKeyEx(0);    //100ms���� Ű �Է��� �����°��� ��ٸ���. Ű �Է��� �ȵ����� ��� �ݺ����� ���� �� ����ȴ�.   //�ƹ� ���ڳ� ���͵� �������
						   //waitKey()�� ����ϸ� ����Ű ���� 0���� ��ȯ�ȴ�. ��� waitKeyEx()�� ����ϸ� ��ü Ű���� ��ȯ�ϱ� ������ ����Ű�� ��ü Ű���� switch���� �־��ָ� 
						   //����Ű�� ����� �Է¹��� �� �ִ�.

		if (key == 27) break;							//ESC �Է� 

		switch (key) {

		case 'a'	: cout << " a Ű �Է� " << endl; break;
		case 'b'	: cout << " b Ű �Է� " << endl; break;
		case 0x41	: cout << " A Ű �Է� " << endl; break;
		case 66		: cout << " B Ű �Է� " << endl; break;
		
		case 0x250000 : cout << " ���� ȭ��ǥ Ű �Է� " << endl; break;
		case 0x260000 : cout << " ���� ȭ��ǥ Ű �Է� " << endl; break;
		case 0x270000 : cout << " ������ ȭ��ǥ Ű �Է� " << endl; break;
		case 0x280000 : cout << " �Ʒ��� ȭ��ǥ Ű �Է� " << endl; break;
		
		}

	}
	
	return 0;
}

