#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Print(int* p, int k);
void my_sort(int array[], int k);

int main() {
	srand((unsigned int)time(NULL));
	cout << "从键盘输入一个正整数n" << endl;
	int n;
	cin >> n;
	//确定是n维的数组不是长度为n的动态数组???
	//动态数组要放堆区
	//array 容器的大小是固定的
	int* p = new int[n];
	int* ghost_p = p;
	for (int i = 0; i < n; i++) {
		int randint = rand() % 9991 + 10;
		*(ghost_p++) = randint;
	}

	Print(p, n);
	my_sort(p, n);
	cout << endl;
	Print(p, n);

}

void Print(int* p, int k) {
	for (int i = 0; i < k; i++) {
		cout << *(p++) << "\t";
	}
	cout << endl;
}

void my_sort(int array[], int k) {
	bool op = false;
	int* tmp_ptr;
	int tmp;
	int* p;
	do {
		op = false;
		p = array;
		tmp_ptr = array;
		for (int i = 0; i < k; i++) {
			if (*p < *tmp_ptr) {
				tmp = *tmp_ptr;
				*tmp_ptr = *p;
				*p = tmp;
				op = true;
			}
			tmp_ptr = p;
			p++;
		}
	} while (op);
}