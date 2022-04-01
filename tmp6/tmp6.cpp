#include <iostream>
using namespace std;

int func() {
	int a = 5;
	int b = 0;
	int c = a / b;
	return c;
}

int main() {
	int d = func();
	cout << d << endl;
}