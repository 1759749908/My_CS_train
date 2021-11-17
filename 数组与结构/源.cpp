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

	cout << "��¼��ѧ����Ϣ��(���� -1 ����)" << endl;
	for (int u = 0; u < 40; u++) {
		for (int i = 0; i < 5; i++) {
			cin >> tmp_ID;
			if (tmp_ID == -1) { goto freedom; }
			cin >> tmp_name;
			cin >> tmp_MT;
			cin >> tmp_EN;
			cin >> tmp_PH;
			student_list.push_back(student(tmp_name, tmp_ID, tmp_MT, tmp_EN, tmp_PH));
			cout << "����¼��ѧ����Ϣ��(���� -1 ����)" << endl;
		}
	}

freedom:

	my_sort(student_list);

	//���
	cout << "ѧ��\t" << "����\t" << "��ѧ\t" << "Ӣ��\t" << "����\t" << "�ܷ�\t" << "ƽ����" << endl;
	for (vector<student>::iterator it = student_list.begin(); it != student_list.end(); it++) {
		cout << (*it).ID << "\t" << (*it).name << "\t" << (*it).MT << "\t" << (*it).EN << "\t" << (*it).PH << "\t" << (*it).SUM << "\t" << (*it).AVE << endl;
	}

	cout << "\n��������һ��ѧ�ţ����ҳ���ѧ���ڰ༶�е��������俼�Է�����" << endl;
	int ID;
	cin >> ID;

	int i = 0;

	for (vector<student>::iterator it = student_list.begin(); it != student_list.end(); it++) {
		i++;
		if ((*it).ID == ID) {
			cout << "�ŵ�" << i << "��" << endl;
			cout << "ѧ��\t" << "����\t" << "��ѧ\t" << "Ӣ��\t" << "����\t" << "�ܷ�\t" << "ƽ����" << endl;
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
	//ð������
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


