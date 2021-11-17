#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct student {
	string name;
	int ID, MT, EN, PH;
	int SUM;
	double AVE;

	student(const string& name,const int& ID,const int& MT,const int& EN,const int& PH) {
		this->name = name;
		this->ID = ID;
		this->MT = MT;
		this->EN = EN;
		this->PH = PH;
		SUM = MT + EN + PH;
		AVE = SUM / 3.0;
	}
};

void my_swap(student& A, student& B);
void my_sort(vector<student>& student_list);

int main()
{
	vector<student> student_list;

	string tmp_name;
	int tmp_ID;
	int tmp_MT;
	int tmp_EN;
	int tmp_PH;

	cout << "请录入学生信息：(输入 -1 结束)" << endl;
	for (int u = 0; u < 40; u++) {
		for (int i = 0; i < 5; i++) {
			cin >> tmp_ID;
			if (tmp_ID == -1) { goto freedom; }
			cin >> tmp_name;
			cin >> tmp_MT;
			cin >> tmp_EN;
			cin >> tmp_PH;
			student_list.push_back(student(tmp_name, tmp_ID, tmp_MT, tmp_EN, tmp_PH));
			cout << "请再录入学生信息：(输入 -1 结束)" << endl;
		}
	}

freedom:

	my_sort(student_list);

	//输出
	cout << "学号\t" << "姓名\t" << "数学\t" << "英语\t" << "物理\t" << "总分\t" << "平均分" << endl;
	for (vector<student>::iterator it = student_list.begin(); it != student_list.end(); it++) {
		cout << (*it).ID << "\t" << (*it).name << "\t" << (*it).MT << "\t" << (*it).EN << "\t" << (*it).PH << "\t" << (*it).SUM << "\t" << (*it).AVE << endl;
	}

	cout << "\n任意输入一个学号，查找出该学生在班级中的排名及其考试分数：" << endl;
	int ID;
	cin >> ID;

	int i = 0;

	for (vector<student>::iterator it = student_list.begin(); it != student_list.end(); it++) {
		i++;
		if ((*it).ID == ID) {
			cout << "排第" << i << "名" << endl;
			cout << "学号\t" << "姓名\t" << "数学\t" << "英语\t" << "物理\t" << "总分\t" << "平均分" << endl;
			cout << (*it).ID << "\t" << (*it).name << "\t" << (*it).MT << "\t" << (*it).EN << "\t" << (*it).PH << "\t" << (*it).SUM << "\t" << (*it).AVE << endl;
		}
	}

}

void my_swap(student& A, student& B) {
	student tmp = A;
	A = B;
	B = tmp;
}

void my_sort(vector<student>& student_list) {
	//冒泡排序
	bool op = false;
	do {
		op = false;
		for (vector<student>::iterator it = student_list.begin();;) {
			student& tmp_student = *it;
			if (++it == student_list.end()) { break; }
			if ((*it).SUM > tmp_student.SUM) {
				op = true;
				my_swap(*it, tmp_student);
			}

		}
	} while (op == true);
}


