//#include <iostream>
//using namespace std;
//
//void test() {
//	cout << "Hey,boy" << endl;
//}
//
//int main() {
//
//	unsigned char* p_MARK = (unsigned char*)test;
//
//	for (; p_MARK < (unsigned char*)test + 30; p_MARK++) {
//		if (*p_MARK == 0xCC) {
//			//(* p_MARK)++;
//			cout << "Don't debug me!" << endl;
//			exit(1);
//		}
//	}
//
//	test();
//}


#include<iostream>
using namespace std;
int main()
{
	char* a, * b, * c;
	int n, m;
	cin >> n >> m;
	a = new char[n];
	b = new char[m];
	c = new char[n + m + 1];
	cin >> a;
	cin >> b;
	cout << &a << endl;
	cout << &b << endl;

	for (int i = 0; i < n; i++)
	{
		c[i] = a[i];
	}
	for (int i = n; i < n + m; i++)
	{
		c[i] = b[i - n];
	}
	for (int i = 0; i < n + m; i++)
	{
		cout << c[i];
	}
	delete[]a;
	delete[]b;
	delete[]c;
}