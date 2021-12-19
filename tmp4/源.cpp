#include <iostream>
using namespace std;

long long my_pow(long long n, long long k) {
	long long ans = 1;
	while (k != 0) {
		if (k & 1) {
			ans = ans * n % 1000000007;
		}
		if (ans == 0) {
			return 0;
		}
		k >>= 1;
		n = n * n % 1000000007;
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	long long k;
	long long ans;

	while (cin >> n >> k) {
		ans = my_pow(n, k) - n;

		if (ans >= 0) {
			cout << ans << "\n";
		}
		else {
			cout << 1000000007 + ans << "\n";
		}
	}
}
