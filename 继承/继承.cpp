#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;

class Student {
protected:
	string name = "无名氏";
	long long ID = NULL;
	double AVG = NULL;
	double SUM = NULL;
	double EN = NULL;
	double MT = NULL;

public:
	virtual void Input(const string&, const long long&, const double&, const double&, const double&) {}
	virtual void Show() {}
};

class ComputerScienceStudent : public Student {
public:
	void Input(const string& name, const long long& ID, const double& EN, const double& MT, const double& AI);
	void Show();
	ComputerScienceStudent() {}
private:
	double AI = NULL;
};

class NetworkEngineeringStudent : public Student {
public:
	void Input(const string& name, const long long& ID, const double& EN, const double& MT, const double& CN);
	void Show();
	NetworkEngineeringStudent() {}
private:
	double CN = NULL;
};

class SoftwareEngineeringStudent : public Student {
public:
	void Input(const string& name, const long long& ID, const double& EN, const double& MT, const double& SE);
	void Show();
	SoftwareEngineeringStudent() {}
private:
	double SE = NULL;
};

vector <std::string> last_name = { "陈","李","王","滨","黄","习" };
vector <std::string> first_name = { "嘉","而","案","时","挨","谷","氨","酸","挨","个","傲","视","额","阿","嘎","拉","过","未","沟","通","是","个","文","化","个","案","上","午","好" };
string get_name();

int main()
{
	srand(unsigned(time(NULL)));

	Student* stu[100];
	stu[0] = new ComputerScienceStudent;

	for (int i = 0; i < 100; i++) {
		switch (rand() % 3) {
		case 0:
			stu[i] = new ComputerScienceStudent;
			break;
		case 1:
			stu[i] = new NetworkEngineeringStudent;
			break;
		case 2:
			stu[i] = new SoftwareEngineeringStudent;
			break;
		}
	}

	long long i1 = 0;

	for (int i = 0; i < 100; i++) {
		stu[i]->Input(get_name(), 32106500000LL + ++i1, rand() % 61 + 40, rand() % 61 + 40, rand() % 61 + 40);
	}

	for (int i = 0; i < 100; i++) {
		stu[i]->Show();
	}

	for (int i = 0; i < 100; i++) {
		delete stu[i];
	}
}

string get_name() {
	string name_temp;
	size_t len_last_name = last_name.size();
	size_t len_first_name = first_name.size();

	int index_last_name = (rand() % len_last_name) / 2;
	int index_first_name = (rand() % len_first_name) / 2;
	name_temp.append(last_name[index_last_name]);
	name_temp.append(first_name[index_first_name]);

	if (rand() % 10 > 2) {
		index_first_name = (rand() % len_first_name) / 2;
		name_temp.append(first_name[index_first_name]);
	}
	return name_temp;
}

void ComputerScienceStudent::Input(const string& name, const long long& ID, const double& EN, const double& MT, const double& AI) {
	Student::name = name;
	Student::ID = ID;
	this->EN = EN;
	this->MT = MT;
	this->AI = AI;
}

void ComputerScienceStudent::Show() {
	cout << "姓名：" << name
		<< setw(14 - name.size()) << "学号：" << ID
		<< "\t" << "英语：" << EN
		<< "\t" << "数学：" << MT
		<< "\t" << "人工智能：" << AI
		<< endl;
}

void NetworkEngineeringStudent::Input(const string& name, const long long& ID, const double& EN, const double& MT, const double& CN) {
	Student::name = name;
	Student::ID = ID;
	this->EN = EN;
	this->MT = MT;
	this->CN = CN;
}

void NetworkEngineeringStudent::Show() {
	cout << "姓名：" << name
		<< setw(14 - name.size()) << "学号：" << ID
		<< "\t" << "英语：" << EN
		<< "\t" << "数学：" << MT
		<< "\t" << "网络工程：" << CN
		<< endl;
}

void SoftwareEngineeringStudent::Input(const string& name, const long long& ID, const double& EN, const double& MT, const double& SE) {
	Student::name = name;
	Student::ID = ID;
	this->EN = EN;
	this->MT = MT;
	this->SE = SE;
}

void SoftwareEngineeringStudent::Show() {
	cout << "姓名：" << name
		<< setw(14 - name.size()) << "学号：" << ID
		<< "\t" << "英语：" << EN
		<< "\t" << "数学：" << MT
		<< "\t" << "软件工程：" << SE
		<< endl;
}