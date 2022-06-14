/*假设有向量X = ( x1, x2,…, xn)和Y = ( y1, y2,…, yn )
编写程序定义向量类Vector，重载运算符实现向量之间的加、减、乘、赋值、输入、输出功能。
注意检测运算的合法性。
Vector类改写为模板类,使向量的数据成员为抽象类。
main函数用int、double, float 实例化,测试Vector类。
*/
#include<iostream>
using namespace std;
template<typename T>
class T_Vector
{
private:
	int dimen;
	T* p;
public:
	T_Vector(int);
	T_Vector(int len, const T_Vector<T>& v);//拷贝构造函数
	T_Vector(const T_Vector<T>& v);//真的拷贝构造函数
	~T_Vector();
	void operator=(T_Vector<T> v);//赋值函数
	template<typename T> friend T_Vector<T> operator+(T_Vector<T> v1, T_Vector<T> v2);//加法
	template<typename T> friend T_Vector<T> operator-(T_Vector<T> v1, T_Vector<T> v2);//减法
	template<typename T> friend T_Vector<T> operator*(T_Vector<T> v1, T_Vector<T> v2);//乘法
	template<typename T> friend ostream& operator<<(ostream& cout, T_Vector<T> v);//输出
	template<typename T> friend istream& operator>>(istream& cin, T_Vector<T>& v);//输入

};
template<typename T>
T_Vector<T>::T_Vector(int len) :dimen{ len }
{
	p = new T[len];
	for (int i = 0; i < len; i++)
	{
		p[i] = 0;
	}
}


template<typename T>
T_Vector<T>::T_Vector(int len, const T_Vector<T>& v) :dimen{ len }/*为什么长度需要单独设置成一个参数，不然输出的数据永远就是初始值？*/
{
	p = new T[dimen];
	for (int i = 0; i < dimen; i++)//深拷贝
	{
		p[i] = v.p[i];
	}
}

template<typename T>
T_Vector<T>::T_Vector(const T_Vector<T>& v) {
	this->dimen = v.dimen;
	this->p = new T[this->dimen];
	for (int i = 0; i < this->dimen; i++)//深拷贝
	{
		this->p[i] = v.p[i];
	}
}

template<typename T>
T_Vector<T>::~T_Vector()
{
	delete[]p;
	dimen = 0;
	/*为什么析构总是错的？*/
}

template<typename T>//赋值
void T_Vector<T>::operator=(T_Vector<T> v)
{
	dimen = v.dimen;
	for (int i = 0; i < dimen; i++)//深拷贝
	{
		p[i] = v.p[i];
	}
}

template<typename T> //加法
T_Vector<T> operator+(T_Vector<T> v1, T_Vector<T> v2)
{
	if (v1.dimen != v2.dimen)
	{
		cout << "wrong" << endl;
		abort();
	}
	else
	{
		T_Vector<T>result(v1.dimen);
		for (int i = 0; i < v1.dimen; i++)
		{
			result.p[i] = v1.p[i] + v2.p[i];
		}
		return result;

	}
}
template<typename T>//减法
T_Vector<T> operator-(T_Vector<T> v1, T_Vector<T> v2)
{
	if (v1.dimen != v2.dimen)
	{
		cout << "wrong" << endl;
		abort();
	}
	else
	{
		T_Vector<T>result(v1.dimen);
		for (int i = 0; i < v1.dimen; i++)
		{
			result.p[i] = v1.p[i] - v2.p[i];
		}
		return result;

	}
}
template<typename T>//乘法
T_Vector<T> operator*(T_Vector<T> v1, T_Vector<T> v2)
{
	if (v1.dimen != v2.dimen)
	{
		cout << "wrong" << endl;
		abort();
	}
	else
	{
		T_Vector<T>result(v1.dimen);
		for (int i = 0; i < v1.dimen; i++)
		{
			result.p[i] = v1.p[i] * v2.p[i];
		}
		return result;

	}
}

template<typename T>//输出
ostream& operator<<(ostream& cout, T_Vector<T> v)
{
	cout << "(";
	for (int i = 0; i < v.dimen; i++)
	{

		cout << v.p[i] << ",";
	}
	cout << '\b' << ")";
	return cout;
}
template<typename T>//输入
istream& operator>>(istream& cin, T_Vector<T>& v)
{
	for (int i = 0; i < v.dimen; i++)
	{
		cin >> v.p[i];
	}
	return cin;
}
void test_int()
{
	//T_Vector<int>v1(2);
	const T_Vector<int>v1(2);

	cout << v1 << endl;
	T_Vector<int>v2(3);
	cout << v2 << endl;
	v2 = v1;
	cout << v2 << endl;
	cout << "input" << endl; cin >> v2;
	cout << v2 << endl;
}
void test_double()
{
	T_Vector<double>v1(2);
	cout << v1 << endl;
	T_Vector<double>v2(3);
	cout << v2 << endl;
	v2 = v1;
	cout << v2 << endl;
	cout << "input" << endl; cin >> v2;
	cout << v2 << endl;
}
void test_float()
{
	T_Vector<float>v1(2);
	cout << "input" << endl; cin >> v1;
	cout << v1 << endl;
	T_Vector<float>v2(v1);
	cout << v2 << endl;
}
int main()
{
	test_int();
	cout << endl;
	//test_double();
	cout << endl;
	test_float();
	cout << endl;
}

