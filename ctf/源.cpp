#include <iostream>
#include <string>
using namespace std;
int main()
{
    string password = "akhb~chdaZrdaZudqduvdZvvv|";
    string password2;
    for (char i : password) {
		password2.push_back((i - 1) ^ 6);
        //xorº”√‹
    }
    cout << password2 << endl;

    return 0;
}