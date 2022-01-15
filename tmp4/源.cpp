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
	int birthday;	//Ӧ��û���ܻʮ����ɣ�
	string phone_string;	//��һ���� 86-020-12345687 �����ı����鷳��
};
vector<People*> people;

class Teacher : public People {

protected:
	string degree;
	string title;
	string salary_string;	//��һ�������֡�
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
		cout << "�û������ļ�������" << endl;
	}
	else if (ifs.eof()) {
		cout << "�û�����Ϊ��" << endl;
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
		<< "************************************************��ӭ������Ա����ϵͳ************************************************\n"
		<< "********************************************************************************************************************\n"
		<< "*                 ���ܣ�1�����ݲ�ѯ��2�����ӣ�3��ɾ����4���޸���Ա�Լ���Ϣ��5����Ա����ͳ�ƣ�6���ļ�����           *\n"
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
		cout << "ָ����������������" << endl;
		cin.clear();
		cin.ignore();
		goto reinput;
	}
	system("cls");

}

void data_search() {
	string key;
	cout << "������Ҫ���ҵ����ݣ�ȫ����ƥ�䣩��" << endl;
	cin >> key;
	for (const auto& i : people) {
		if (i->match(key)) {
			cout << i << endl;
		}
	}
}

void data_add() {
	int choice;
	cout << "��Ҫ���ʲô����" << endl;
	cout << "1-��ʦ��2-��ʿ����3-�о�����4-��������5-��ְ��ʿ" << endl;
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