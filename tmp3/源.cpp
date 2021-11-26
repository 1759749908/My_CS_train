#include<iostream>
using namespace std;
double good(double l)
{
	return 4 * l;
}
int main()
{
	double x = 1.23;

	double (*pfun[4])(double);
	pfun[0] = good;
	cout << (*pfun[0])(x) << endl;
}