#include <iostream>
#include <vector>
using namespace std;

int main() {
	restart:
	int n,i = 2;

	while (1) {

		if (n % i == 0) {
			cout << i << endl;
			n = n / i;
			if (n == 1) goto restart;

		}
		else i++;


	}
}