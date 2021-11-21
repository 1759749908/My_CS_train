#include <iostream>
using namespace std;

int my_pow(int a, int b) {
    int ans = 1;
    int base = a;

    while (b) {
        if (b & 1) {
            ans *= base;
        }
        base *= base;
        b >>= 1;
    }

    return ans;
}

int main()
{
    cout << my_pow(2, 5) << endl;

}