#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void ��������();
void P55Q10();
void P55Q12();
void P55Q13();
void P55Q14();

int main() {
#define algorithm_version 2		//�����������㷨��1��Ŀǰ���Ч���㷨��
	int choice;
	cout << "�������ѡ��" << endl;
	cout << "1����������" << endl;
	cout << "2��P55Q10" << endl;
	cout << "3��P55Q12" << endl;
	cout << "4��P55Q13" << endl;
	cout << "5��P55Q14" << endl;
	//cin >> choice;
	choice = 1;

	switch (choice) {
	case 1:��������(); break;
	case 2:P55Q10(); break;
	case 3:P55Q12(); break;
	case 4:P55Q13(); break;
	case 5:P55Q14(); break;
	}



}


void ��������() {

	while (true) {
		unsigned long long n, d = 2, i = 0;
		vector<unsigned long long> prime;
		vector<pair<unsigned long long, unsigned long long>> twin_prime;
		string buffer;
		bool flag = false;
		bool mode = 0;

		cout << "����0Ϊ�������������1Ϊ�������������";
		cin >> mode;

		if (mode) {
			cout << "������ٸ�����������";
			cin >> n;
			cout << "����֮��ľ����ǣ�";
			cin >> d;
		}
		else {
			cout << "������ٸ�������";
			cin >> n;
		}


		clock_t start = clock();
		unsigned long long length = 0;
		for (unsigned long long start = 2; length < n; start++) {
#if algorithm_version == 0
			//����㷨
			flag = true;
			for (i = 2; i < start; i++) {
				if (start % i == 0) {
					break;
				}
			}
			if (i == start) {
				flag = false;
				prime.emplace_back(start);
				if (!mode) {
					length++;
				}
			}

#endif

#if algorithm_version == 1
			//����������㷨
			flag = true;
			for (i = 2; i <= sqrt(start); i++) {
				if (start % i == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				prime.emplace_back(start);
				if (!mode) {
					length++;
				}
			}
#endif

#if algorithm_version == 2
			//ɸ��
			//���㷨��Ȼ������㷨������������
			//�������CPU�ķ�֧Ԥ���Լ�CPU Cache���������йء�
			flag = true;
			if (!prime.empty()) {
				for (const auto& i : prime) {
					if (start % i == 0) {
						flag = false;
						break;
					}
			}
		}
			if (flag) {
				prime.emplace_back(start);
				if (!mode) {
					length++;
				}
			}

#endif

			if (mode && flag) {
				unsigned long long i = prime.size();
				if (i > 1) {
					if (prime[i - 1] - prime[i - 2] == d) {
						twin_prime.emplace_back(make_pair(prime[i - 2], prime[i - 1]));
						length++;
					}
				}
			}
	}

		clock_t end = clock();

		if (mode) {
			for (const auto& i : twin_prime) {
				buffer.append(to_string(i.first) + '\t' + to_string(i.second));
				buffer.push_back('\n');
			}
		}
		else {
			//for (const auto& i : prime) {
			//	buffer.append(to_string(i));
			//	buffer.push_back('\n');
			//}

			for (const auto& i : prime) {
				buffer.append(to_string(i));
				buffer.push_back(',');
			}

		}

		cout << buffer;		//cout���������ʱ��Ч�ʵͣ����û��������Լӿ�����ٶ�
		cout << "������" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
}
}

void P55Q10() {

	int n1, n2, n3;
	for (int i = 100; i < 1000; i++) {
		n1 = i / 100;
		n2 = (i / 10) % 10;
		n3 = i % 10;
		if (i == pow(n1, 3) + pow(n2, 3) + pow(n3, 3)) cout << i << endl;

	}
}

void P55Q12() {
	while (true) {
		int length;
		cout << "���������α߳���";
		cin >> length;
		for (int i = 1; i <= length; i++) {

			if (i == 1 || i == length) {
				for (int u = 1; u <= length; u++) cout << "* ";
				cout << endl;
			}

			else {
				for (int u = 1; u <= length; u++) {
					if (u == 1 || u == length) cout << "* ";
					else cout << "  ";
				}
				cout << endl;
			}
		}

	}
}

void P55Q13() {
	int L;
	int R;
	for (int X = 0; X < 10; X++)for (int Y = 0; Y < 10; Y++)for (int Z = 0; Z < 10; Z++)
	{
		L = X * 100 + Y * 10 + Z;
		R = Y * 100 + Z * 10 + Z;
		if (L + R == 532) cout << "X:" << X << "\tY:" << Y << "\tZ:" << Z << endl;
	}

}
void P55Q14() {
	while (true) {
		vector<char> number;
		bool mode;
		cout << "����0���ܣ�����1���ܣ�";
		cin >> mode;

		if (mode) {
			string tmp;
			cout << "����ȴ����ܵ����֣�";
			cin >> tmp;
			if (tmp.size() != 6) {
				cout << "error" << endl;
				continue;
			}

			//������6λ��ѭ���������ˡ�
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();

			auto iter = number.cbegin();
			cout << (*(iter++) + 3) % 10;
			cout << (*(iter++) + 3) % 10;
			cout << (*(iter++) + 3) % 10;
			cout << (*(iter++) + 3) % 10;
			cout << (*(iter++) + 3) % 10;
			cout << (*(iter++) + 3) % 10;
			cout << endl;
		}

		else {
			string tmp;
			cout << "����ȴ����ܵ����֣�";
			cin >> tmp;

			if (tmp.size() != 6) {
				cout << "error" << endl;
				exit(1);
			}

			//������6λ��ѭ���������ˡ�
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();
			number.emplace_back(tmp.back() - '0');
			tmp.pop_back();

			auto iter = number.cbegin();
			cout << (*(iter++) + 7) % 10;
			cout << (*(iter++) + 7) % 10;
			cout << (*(iter++) + 7) % 10;
			cout << (*(iter++) + 7) % 10;
			cout << (*(iter++) + 7) % 10;
			cout << (*(iter++) + 7) % 10;
			cout << endl;

		}
	}
}
