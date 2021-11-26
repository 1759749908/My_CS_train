#include <iostream>
using namespace std;

void my_print(int a) {
    cout << "test" << a << endl;
}


int main()
{
    void (* b)(int) = my_print;
    cout << my_print << endl;
    cout << b << endl;


    b(4);
}
