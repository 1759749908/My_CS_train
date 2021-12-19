#include <iostream>
using namespace std;

void hannoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
		printf_s("�ƶ�%d��ԲȦ����%c�ƶ���%c��\n", n, A, C);
    }
    else
    {
        hannoi(n - 1, A, C, B);
        printf_s("�ƶ�%d��ԲȦ����%c�ƶ���%c��\n", n, A, C);
        hannoi(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    cin >> n;

    hannoi(n, 'a', 'b', 'c');
}