#include <iostream>
#include "a.cpp"
using namespace std;

extern int test();

int main() {
	cout << test() << endl;
}