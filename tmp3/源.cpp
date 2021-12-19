//#include <iostream>
//#include <string>
//#include <vector>
//#include <iomanip>
//#include <algorithm>
//using namespace std;
//
//class Student {
//public:
//	string name;
//	int ID;
//	float MT;
//	float EN;
//	float PH;
//	float SUM;
//	float AVG;
//	Student(const string&, const int&, const float&, const float&, const float&);
//	void Display() const;
//};
//
//void stu_print(const vector<Student>&);
//void find_stu(const vector<Student>&);
//void m_sort(vector<Student> exam, const int& ID = -1);
//
//int main() {
//	vector<Student> exam;
//	exam.emplace_back(Student("张三", 001, 0, 0, 0));
//	exam.emplace_back(Student("李四", 002, 60, 60, 60));
//	exam.emplace_back(Student("王五", 003, 150, 150, 150));
//	exam.emplace_back(Student("小明", 004, 60, 76, 78));
//	exam.emplace_back(Student("李雷", 005, 87, 34, 87));
//	exam.emplace_back(Student("韩梅梅", 006, 83, 38, 43));
//	exam.emplace_back(Student("李华", 007, 35, 87, 68));
//
//
//	int choice;
//	while (true) {
//		cout <<
//			"***********************        欢迎进入考试系统        ***********************\n" <<
//			"操作说明：0-退出系统；1-输出名次表(按学号)；2-查找学生；3-输出名次表(按总分)；\n" <<
//			"请输入操作：";
//
//		if (!(cin >> choice)) {
//			cout << "输入非法，请重试" << endl;
//			cin.clear();
//			cin.ignore();
//			continue;
//		}
//
//		switch (choice) {
//		case 0:
//			exit(0);
//		case 1:
//			stu_print(exam);
//			break;
//		case 2:
//			find_stu(exam);
//			break;
//		case 3:
//			m_sort(exam);
//			break;
//		}
//
//	}
//}
//
//
//Student::Student(
//	const string& name,
//	const int& ID,
//	const float& MT,
//	const float& EN,
//	const float& PH)
//	:
//	name(name),
//	ID(ID),
//	MT(MT),
//	EN(EN),
//	PH(PH),
//	SUM(MT + EN + PH),
//	AVG(SUM / 3)
//{
//	//据说初始化列表性能高
//}
//
//void Student::Display() const {
//	cout << "姓名：" << name << setw(20 - name.size()) << " 学号：" << ID << " \t数学：" << MT << " \t英语：" << EN << " \t物理：" << PH << " \t总分：" << SUM << " \t平均分：" << AVG << endl;
//}
//
//void stu_print(const vector<Student>& exam) {
//	for (vector<Student>::const_iterator it = exam.cbegin(); it != exam.cend(); it++) {
//		it->Display();
//	}
//}
//
//void find_stu(const vector<Student>& exam) {
//	int ID;
//	cout << "输入你想查找的学生学号：";
//	cin >> ID;
//	m_sort(exam, ID);
//	//for (vector<Student>::const_iterator it = exam.cbegin(); it != exam.cend(); it++) {
//	//	if (it->ID == ID) {
//	//		it->Display();
//	//	}
//	//}
//}
//
//void m_sort(vector<Student> exam, const int& ID) {
//	bool opt = true;
//	while (opt) {
//		opt = false;
//		for (int i = 0; i < exam.size() - 1; i++) {
//			if (exam[i].SUM < exam[i + 1].SUM) {
//				swap(exam[i], exam[i + 1]);
//				opt = true;
//			}
//		}
//	}
//
//	if (ID == -1) {
//		stu_print(exam);
//	}
//	else {
//		for (int i = 0; i < exam.size(); i++) {
//			if (exam[i].ID == ID) {
//				exam[i].Display();
//				cout << "排名为：" << i + 1 << endl;
//				return;
//			}
//		}
//	}
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	string a;
//	string b;
//	cout << "请输入第一个字符串：";
//	cin >> a;
//	cout << "请输入第二个字符串：";
//	cin >> b;
//
//	string c;
//	for (auto i : a) {
//		c.push_back(i);
//	}
//
//	for (auto i : b) {
//		c.push_back(i);
//	}
//
//	cout << c << endl;
//}

//#include <iostream>
//#include <string>
//#include <ctime>
//using namespace std;
//
//void Print(int* p, int k) {
//	for (int i = 0; i < k; i++) {
//		cout << p[i] << "\t";
//		if (!((i + 1) % 20)) {
//			cout << endl;
//		}
//	}
//	cout << endl;
//}
//
//void my_sort(int* p, int k) {
//	bool opt = true;
//	while (opt) {
//		opt = false;
//		for (int i = 0; i < k - 1; i++) {
//			if (p[i] < p[i + 1]) {
//				swap(p[i], p[i + 1]);
//				opt = true;
//			}
//		}
//	}
//	Print(p, k);
//
//}
//
//int main() {
//	cout << "要多少个数？";
//	srand(unsigned(time(NULL)));
//	int n;
//	cin >> n;
//	int* p = new int[n + 1];
//	for (int i = 0; i < n; i++) {
//		p[i] = rand() % 9001 + 10;
//	}
//
//	my_sort(p, n);
//
//	int ins;
//	cout << "插入一个数：";
//	cin >> ins;
//	p[n] = ins;
//	my_sort(p, n + 1);
//}



#include <iostream>
using namespace std;

void test() {
	cout << "Hey,boy" << endl;
}

int main() {

	unsigned char* p = (unsigned char*)main;
	unsigned char MARK = *(unsigned char*)test;

	for (; p < (unsigned char*)main + 34; p++) {
		if (*p == 0xCC) {
			goto dangerous;
		}
	}

	if (MARK == 0xCC) {
		goto dangerous;
	}

	test();

	exit(0);
dangerous:
	cout << "Don't debug me!" << endl;
	exit(1);
}