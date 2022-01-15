#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class People {
public:
	virtual bool match(const string&) = 0;
	virtual void changes() = 0;
	virtual bool type_in(istream& is) = 0;
	virtual string input_tips() = 0;
	virtual istream& input(istream&) = 0;
	virtual ostream& output(ostream&) const = 0;

	People() = default;
	virtual ~People() = default;
protected:
	long long ID;
	string gender;
	string name;
	int birthday;	//应该没人能活到十万年吧？
	string phone_string;	//万一出现 86-020-12345687 这样的表达就麻烦了
};
vector<People*> people;

class Teacher : public People {

protected:
	string degree;
	string title;
	string salary_string;	//不一定是数字。
};

class Student : public People {

protected:
	string major;
	string grade;
	int date;
};

class phDStudent : public Student {
	
protected:
	string field;
	string papers;
};

class GraduateStudent : public Student {

protected:
	string field;
	string papers;
};

class Undergraduate : public Student {

protected:
	float english, math, PE;
};

class PartTimePhD : virtual public Teacher, virtual public phDStudent {

};

void input_data(ifstream&, vector<People*>&);
void showUI();
void waiting_order();
void data_search();
void data_add();
void data_remove();
void data_change();
void data_statistics();
void data_save();

ostream& operator<<(ostream&, const People *);
istream& operator>>(istream&, People *);

int main() {
	ifstream ifs;
	ifs.open("Database.db");
	if (!ifs.is_open()) {
		cout << "用户数据文件不存在" << endl;
	}
	else if (ifs.eof()) {
		cout << "用户数据为空" << endl;
	}
	else {
		input_data(ifs, people);
		ifs.close();
	}
	showUI();
	while (true) waiting_order();

}

void showUI() {
	cout
		<< "********************************************************************************************************************\n"
		<< "************************************************欢迎来到人员管理系统************************************************\n"
		<< "********************************************************************************************************************\n"
		<< "*                 功能：1—数据查询，2—增加，3—删除，4—修改人员以及信息，5—人员各类统计，6—文件保存           *\n"
		<< "********************************************************************************************************************\n";
}

void waiting_order() {
	int order;
	cout << ">>";
	reinput:
	cin >> order;
	switch (order)
	{
	case 1:
		data_search();
		break;
	case 2:
		data_add();
		break;
	case 3:
		data_remove();
		break;
	case 4:
		data_change();
		break;
	case 5:
		data_statistics();
		break;
	case 6:
		data_save();
		break;
	default:
		cout << "指令有误，请重新输入" << endl;
		cin.clear();
		cin.ignore();
		goto reinput;
	}
	system("cls");

}

void data_search() {
	string key;
	cout << "请输入要查找的数据（全数据匹配）：" << endl;
	cin >> key;
	for (const auto& i : people) {
		if (i->match(key)) {
			cout << i << endl;
		}
	}
}

void data_add() {
	int choice;
	cout << "你要添加什么？：" << endl;
	cout << "1-教师，2-博士生，3-研究生，4-本科生，5-兼职博士" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		people.emplace_back(new );
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}	


}
void data_remove();
void data_change();
void data_statistics();
void data_save();



ostream& operator<<(ostream& os, const People* person) {
	return person->output(os);
}

istream& operator>>(istream& is, People* person) {
	return person->input(is);
}