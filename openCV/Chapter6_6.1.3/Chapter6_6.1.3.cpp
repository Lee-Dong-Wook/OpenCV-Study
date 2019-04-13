#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.1.3 �ݺ��ڸ� ���� ��� ���� ���� 

//�ݺ��ڸ� ����ؼ� ������ ��ҿ� ����
//�ݷ����� �� ��Ҹ� ��ȸ�ϱ� ���� ����Ŭ����, �ݷ����� Ÿ���̳� ���� ������ ������� �����ϰ� 
//��� �����ϱ⿡ ���� ����� �Ϲ�ȭ �� �� �ִ� ���� 

//MatIterator_ �б�, ���� ���� 
//MatConstIterator_ �б⸸ ����

//���� ��� 
//m1 =
//[1, 2, 3;
// 1, 2, 3;
// 1, 2, 3]

//m2 =
//[1, 2, 3;
// 1, 2, 3;
// 1, 2, 3]

//m3 =
//[0, 1, 2, 0, 2, 4, 0, 3, 6;
// 0, 1, 2, 0, 2, 4, 0, 3, 6;
// 0, 1, 2, 0, 2, 4, 0, 3, 6]

int main() {

	uchar data[] = {

		1, 2, 3,
		1, 2, 3,
		1, 2, 3,
	};

	Mat m1(3, 3, CV_8UC1, data);			// uchar�� �迭�� �ʱ�ȭ 
	Mat m2(m1.size(), m1.type());			//m1��İ� ���� ũ��� Ÿ��
	Mat m3(m1.size(), CV_32FC3);            //m1��İ� ���� ũ��� 3ä�� float�� 

	MatConstIterator_<uchar> it_m1 = m1.begin<uchar>();		//�б� ���� �� ��� ������ġ�� �ݺ��� ���� 
	MatIterator_<uchar>		 it_m2 = m2.begin<uchar>();     //�б� �� ���� 
	Mat_<Vec3f>::iterator    it_m3 = m3.begin<Vec3f>();

	for (; it_m1 != m1.end<uchar>(); ++it_m1, ++it_m2, ++it_m3) {

		*it_m2 = *it_m1;	//������(de-referencing) �����Ͱ� ����Ű�� �ִ� �� 
		
		/*(*it_m3)[0] = *it_m1 * 0.5f;
		  (*it_m3)[1] = *it_m1 * 0.3f;
		  (*it_m3)[2] = *it_m1 * 0.2f;*/

		for (int i = 0; i < m3.channels(); i++) {

			(*it_m3)[i] = *it_m1 * i;
		}
		

		//*it_m1 = *it_m2;	//it_m1�� const���̱� ������ �����͸� �ٽþ� �� ����		
	}

	cout << "m1 = " << endl << m1 << endl;
	cout << "m2 = " << endl << m2 << endl;
	cout << "m3 = " << endl << m3 << endl;

	return 0;
}