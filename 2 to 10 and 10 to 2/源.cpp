#include <iostream>
#include <vector>
using namespace std;

void iterate(unsigned long long number);
void iterate(vector<bool> Binary, unsigned long long number);

int main() {

	bool mode;
	cout << "����0Ϊ2����ת10���ƣ�����1Ϊ10����ת2���ƣ����������˳���" << endl;
	
	if (!(cin >> mode)) {
		exit(0);
	}

	if (mode) {
		unsigned long long number;
		cout << "������10������(����������)" << endl;
		cin >> number;
		iterate(number);
	}

	else {
		unsigned long long num = 0;
		string binary;
		cout << "������2������(����������)" << endl;
		cin >> binary;
		reverse(binary.begin(), binary.end());
		for (int i = 0; i < binary.size(); i++) {
			if(binary[i] == '1')
			num += unsigned long long(pow(2, i));
		}
		cout << num << endl;
	}

	main();		//�����ڴ��ò��꣬�������Ե��õݹ�ķ���ѭ��
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
