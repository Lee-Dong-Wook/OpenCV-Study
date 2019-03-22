#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void print_vectorInfo(String v_name, vector<int> v) { //���� �������, �̸�, ũ��,���� ��

	cout << "[" << v_name << "] = " << endl;
	if (v.empty()) cout << "���Ͱ� ������ϴ�." << endl;
	else {
		cout << (Mat)v << endl<<endl;
		cout << ((Mat)v).reshape(1, 1) << endl;
	}
		

	cout << ".size() = " << v.size() << endl; 
}

int main() {

	//vectorŬ���� ��� 
	//���� ���� ���� - �迭 ó�� ÷�ڿ�����([])�̿�
	//���� �Ҵ�� �뷮 Ȯ�� vector::capacity()
	//���� �޸� Ȯ�� vector::reserve()

	int arr[] = { 10,20,30,40,50 };							//���� �ʱ�ȭ�� �迭
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));	//�迭�� ���� �ʱ�ȭ 

	print_vectorInfo("v1", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;

	cout << endl; 
	v1.insert(v1.begin() + 2, 100);							//�ε��� 2�� ��ġ�� 100�� ����
	print_vectorInfo("v1�� 2�� �ε����� 100���� ", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl; //size�� capacity�� ���� �ٸ��� ���´�.
															   //���� ���̴� C++ Additional Method of Programming Chap7 ����Ȯ��
	//��ü ���Ұ����� �ϳ� �����Ͽ� 6 ���һ��� �� ���� ������ �����Ͽ� ������ ���� ���Ҵ��� �߻��ϸ�, �޸𸮰� 2���� ����
	//���� v1������ �Ҵ�޸�(capacity)�� 7�̵� 

	v1.erase(v1.begin() + 3);
	print_vectorInfo("v1�� 3�� �ε����� ����", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;

	v1.clear();
	print_vectorInfo("v1�� ���� ��� ����", v1);
	cout << ".capacity() = " << v1.capacity() << endl << endl;
	

	


	
	return 0;

}