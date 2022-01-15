#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//class Matrix
//{
//	double m11, m12, m13, m21, m22, m23, m31, m32, m33;
//public:
//	Matrix() {};
//	//重载运算符">>"
//	friend istream& operator >> (istream& in, Matrix& p);
//	//重载运算符"<<" 
//	friend ostream& operator << (ostream& out,const Matrix& p);
//	friend Matrix operator+ (const Matrix&,const Matrix&);
//};
//
//istream& operator >> (istream& in, Matrix& p) {
//	in >> p.m11 >> p.m12 >> p.m13 >> p.m21 >> p.m22 >> p.m23 >> p.m31 >> p.m32 >> p.m33;
//	return in;
//}
//
//ostream& operator << (ostream& out,const Matrix& p) {
//	out << p.x << " " << p.y;
//	return out;
//}
//
//Matrix operator+ (const Matrix&, const Matrix&) {
//	
//
//}
//
//int main() {
//	Matrix p;
//	cin >> p;
//	cout << p << endl;
//}


struct point {
	point(const double& x, const double& y) : x(x), y(y) {}
	point() = default;
	double x, y;
};

class Graph {
public:
	virtual double area() = 0;
	virtual double girth() = 0;
};

class Polygon : public Graph {
public:
	Polygon(point points[], const int& count) : points(points), count(count) {}

	double area() override {
		double sum_area = 0;

		sum_area += points[count - 1].x * points[0].y - points[0].x * points[count - 1].y;
		for (int i = 0; i < count - 1; i++) {
			sum_area += points[i].x * points[i + 1].y - points[i + 1].x * points[i].y;
		}

		return 0.5 * fabs(sum_area);
	}

	double girth() override {
		double sum_girth = 0;

		sum_girth += sqrt(pow(fabs(points[0].y - points[count - 1].y), 2) + pow(fabs(points[0].x - points[count - 1].x), 2));
		for (int i = 0; i < count - 1; i++) {
			sum_girth += sqrt(pow(fabs(points[i].y - points[i + 1].y), 2) + pow(fabs(points[i].x - points[i + 1].x), 2));
		}

		return sum_girth;
	}

protected:
	point* points;
	int count;
};


int main() {
	srand((unsigned)time(NULL));
	const int N = 10;
	point points[N];
	for (int i = 0; i < N; i++) {
		points[i].x = rand() % 20 - 10;
		points[i].y = rand() % 20 - 10;
	}

	Graph* graph = new Polygon(points, N);


	for (int i = 0; i < N; i++) {
		printf("点%d的坐标：（%lg，%lg）\n", i, points[i].x, points[i].y);
	}

	cout << "面积：" << graph->area() << "\t" << "周长：" << graph->girth() << endl;

}