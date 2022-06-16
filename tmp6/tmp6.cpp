#include <iostream>  
#include "md5.h"  

using namespace std;

int main(int argc, char* argv[])
{
    string str = "!Admin123";
    cout << "md5 of this string: " << md5(str) << endl;
    return 0;
}