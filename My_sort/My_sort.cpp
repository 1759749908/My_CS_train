#include <iostream>
#include<thread>
#include <windows.h>
using namespace std;

template <typename T>
void My_swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template <typename T>
void QuickSort(T array[], int n)
{
	
}

template <typename T>
void BubbleSort(T array[], int n)
{
	bool opt = true;
	while (opt) {
		opt = false;
		for (int i = 0; i < n - 1; i++) {
			if (array[i] > array[i + 1]) {
				opt = true;
				My_swap(array[i], array[i + 1]);
			}
		}
	}
}

template <typename T>
void SelectSort(T array[], int n)
{
	int min_index;
	int u = 0;
	bool opt = true;
	while (n != u) {
		min_index = u;
		for (int i = 0; i < n; i++) {
			cout << array[i] << "    ";
		}
		cout << endl;

		opt = false;
		for (int i = u; i < n; i++) {
			if (array[i] < array[min_index]) {
				min_index = i;
				opt = true;
			}
		}
		if (opt) {
			My_swap(array[u], array[min_index]);
		}

		u++;
	}
}

int main() {
	int a[] = { 4,7,2,1,7,59,16,464,264,95,16 };
	QuickSort(a, size(a));
	for (int i = 0; i < size(a); i++) {
		cout << a[i] << endl;
	}
}