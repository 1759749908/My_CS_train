#include <iostream>
#include <string>
using namespace std;
int main()
{
    string password = "fk_dwqo^njXkcjWg_l";

    for (char i = 0; i <= 18; i++) {
        cout << char(password[i] + i);
    }
    cout << endl;

    return 0;
}