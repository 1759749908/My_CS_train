#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void 孪生素数();
void P55Q10();
void P55Q12();
void P55Q13();
void P55Q14();

int main() {
#define algorithm_version 2		//计算素数的算法，1是目前最高效的算法。
	int choice;
	cout << "输入你的选择：" << endl;
	cout << "1：孪生素数" << endl;
	cout << "2：P55Q10" << endl;
	cout << "3：P55Q12" << endl;
	cout << "4：P55Q13" << endl;
	cout << "5：P55Q14" << endl;
	//cin >> choice;
	choice = 1;

	switch (choice) {
	case 1:孪生素数(); break;
	case 2:P55Q10(); break;
	case 3:P55Q12(); break;
	case 4:P55Q13(); break;
	case 5:P55Q14(); break;
	}



}


void 孪生素数() {

	while (true) {
		unsigned long long n, d = 2, i = 0;
		vector<unsigned long long> prime;
		vector<pair<unsigned long long, unsigned long long>> twin_prime;
		string buffer;
		bool flag = false;
		bool mode = 0;

		cout << "输入0为输出素数，输入1为输出孪生素数：";
		cin >> mode;

		if (mode) {
			cout << "输出多少个孪生素数：";
			cin >> n;
			cout << "素数之间的距离是：";
			cin >> d;
		}
		else {
			cout << "输出多少个素数：";
			cin >> n;
		}


		clock_t start = clock();
		unsigned long long length = 0;
		for (unsigned long long start = 2; length < n; start++) {
#if algorithm_version == 0
			//穷举算法
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
			//改良版穷举算法
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
			//筛法
			//这算法居然比穷举算法还慢！！？？
			//这可能与CPU的分支预测以及CPU Cache的命中率有关。
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

		cout << buffer;		//cout在连续输出时的效率低，设置缓冲区可以加快输出速度
		cout << "花费了" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
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
		cout << "输入正方形边长：";
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
		cout << "输入0加密，输入1解密：";
		cin >> mode;

		if (mode) {
			string tmp;
			cout << "输入等待解密的数字：";
			cin >> tmp;
			if (tmp.size() != 6) {
				cout << "error" << endl;
				continue;
			}

			//反正就6位，循环都不用了。
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
			cout << "输入等待加密的数字：";
			cin >> tmp;

			if (tmp.size() != 6) {
				cout << "error" << endl;
				exit(1);
			}

			//反正就6位，循环都不用了。
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
