#include <iostream>
#include "declare.h"

using namespace std;

int main() {
	while (true) {
		cout << "ÇëÊäÈëm,n:" << endl;
		int m, n;
		cin >> m >> n;
		cout << Fabricate(m, n) << endl;
	}
}
