#include <iostream>
using namespace std;

unsigned long long my_pow(unsigned long long a, unsigned long long b) {
    unsigned long long ans = 1,base = a;

    while (b) {
        if (b & 1) {
            ans *= base;
        }
        base *= base;
        b >>= 1;
    }

    return ans;
}

unsigned long long my_pow_mod(unsigned long long a, unsigned long long b, unsigned long long c) {
    unsigned long long ans = 1, base = a;

    while (b) {
        if (b & 1) {
            ans = ans * base % c;
        }
        base = base * base % c;
        b >>= 1;

    }

    return ans;

}

int main()
{
    cout << my_pow_mod(2, 1000000,998244353) << endl;

}