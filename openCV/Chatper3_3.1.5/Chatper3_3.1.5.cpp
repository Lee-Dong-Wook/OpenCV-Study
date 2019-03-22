#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//Vec 클래스 
	//Vec<Tp,n> -> n개의 매개변수  
	//Point_,Point3_,Scalar_클래스로 형변환 가능 
	//배열첨자[]를 사용하여 벡터 원소 접근 가능 

	//typedef vec<uchar,2> Vec2b
	//typedef vec<uchar,3> Vec3b
	//typedef vec<uchar,4> Vec4b

	//typedef vec<short,2> Vec2s
	//typedef vec<short,3> Vec3s
	//typedef vec<short,4> Vec4s

	//typedef vec<int,2> Vec2i
	//typedef vec<int,3> Vec3i
	//typedef vec<int,4> Vec4i

	//typedef vec<float,2> Vec2f
	//typedef vec<float,3> Vec3f
	//typedef vec<float,4> Vec4f
	//typedef vec<float,6> Vec6f

	//typedef vec<double,2> Vec2d
	//typedef vec<double,3> Vec3d
	//typedef vec<double,4> Vec4d
	//typedef vec<double,6> Vec6d

	Vec <int, 2> v1(5, 12);
	Vec <double, 3> v2(40, 130.7, 125.6);
	Vec2b v3(10, 10);
	Vec6f v4(40.f, 230.25f, 525.6f);
	Vec3i v5(200, 230, 250);

	Vec3d v6 = v2 + (Vec3d)v5;
	Vec2b v7 = (Vec2b)v1 + v3;
	Vec6f v8 = v4 * 20.0f;

	Point pt1 = v1 + (Vec2i)v7;
	//Point3_<int> pt2 = v2; 묵시적 형변환이 되지않아 아래처럼 함. 
	Point3_<int> pt2 = (Point3d)v2;
	
	cout << "[v3] = " << v3 << endl;
	cout << "[v7] = " << v7 << endl; 
	cout << "[v3 * v7] = " << v3.mul(v7) << endl;
	cout << "v8[0] = " << v8[0] << endl; 
	cout << "v8[1] = " << v8[1] << endl;
	cout << "v8[2] = " << v8[2] << endl;
	cout << "[v2] = " << v2 << endl;
	cout << "[pt2] = " << pt2 << endl;

	return 0;
}