#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long table[1000];

long long func(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (table[n] != -1) {
		return table[n];
	}
	else {
		long long ans = func(n - 1) + func(n - 3) + func(n - 8) + func(n - 10) + func(n - 12);
		table[n] = ans;
		return ans;
	}
}

int main() {
	fill_n(table, 1000, -1);
	table[1] = 1;
	table[2] = 1;
	table[3] = 2;
	table[4] = 3;
	table[5] = 4;
	table[6] = 6;
	table[7] = 9;
	table[8] = 11;
	table[9] = 17;

	cout << func(301) << endl;

}