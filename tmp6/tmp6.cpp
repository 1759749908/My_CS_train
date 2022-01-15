#include <iostream>
using namespace std;

int* mmm() {
    int a = 10;
    printf("a->%p\n", &a);
    return &a;
}

int main()
{
    printf("%p\n", mmm());
    printf("%p\n", mmm());
    printf("%p\n", mmm());
    int b = 8;
    printf("%p\n", mmm());
    printf("%p\n", mmm());
    printf("%p\n", mmm());
    printf("%p\n", mmm());
}