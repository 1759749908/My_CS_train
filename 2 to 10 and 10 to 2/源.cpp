#include <iostream>
#include <vector>
using namespace std;

void iterate(unsigned long long number);
void iterate(vector<bool> Binary, unsigned long long number);

int main() {

	bool mode;
	cout << "输入0为2进制转10进制，输入1为10进制转2进制，输入其他退出。" << endl;
	
	if (!(cin >> mode)) {
		exit(0);
	}

	if (mode) {
		unsigned long long number;
		cout << "请输入10进制数(仅限正整数)" << endl;
		cin >> number;
		iterate(number);
	}

	else {
		unsigned long long num = 0;
		string binary;
		cout << "请输入2进制数(仅限正整数)" << endl;
		cin >> binary;
		reverse(binary.begin(), binary.end());
		for (int i = 0; i < binary.size(); i++) {
			if(binary[i] == '1')
			num += unsigned long long(pow(2, i));
		}
		cout << num << endl;
	}

	main();		//反正内存用不完，可以任性的用递归的方法循环
}

void iterate(unsigned long long number) {
	if (number == 0) {
		cout << "0" << endl;
		exit(0);
	}
	int i = 0;
	while (pow(2, i) <= number) { i++; }
	vector<bool> Binary(i);
	i--;
	Binary[i] = 1;
	if (pow(2, i) != number) {
		iterate(Binary, number - unsigned long long(pow(2, i)));
	}
	else {
		reverse(Binary.begin(), Binary.end());
		for (auto i : Binary) {
			cout << i;
		}
		cout << endl;
	}
}

void iterate(vector<bool> Binary, unsigned long long number) {
	int i = 0;
	while (pow(2, i) <= number) { i++; }
	i--;
	Binary[i] = 1;
	if (pow(2, i) != number) {
		iterate(Binary, number - pow(2, i));
	}
	else {
		reverse(Binary.begin(), Binary.end());
		for (auto i : Binary) {
			cout << i;
		}
		cout << endl;
	}
}
