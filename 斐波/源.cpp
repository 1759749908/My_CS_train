#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	while (true) {
		vector<unsigned long long> My_list;
		My_list.emplace_back(1);
		My_list.emplace_back(1);

		unsigned long n;
		cout << "n=";
		cin >> n;

		for (unsigned long i = 2; i <= n; i++) {
			My_list.emplace_back(My_list[i - 2] + My_list[i - 1]);
		}

		unsigned long counter = 1;
		string buffer;
		for (const auto& i : My_list) {
			buffer.append("第" + to_string(counter++) + "位斐波列娜数是：");
			buffer.append(to_string(i));
			buffer.push_back('\n');
		}

		cout << buffer;
	}
}

