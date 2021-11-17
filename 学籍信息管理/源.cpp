#include <iostream>
using namespace std;

struct student {
	string name, sex;
	int id, age, score_cpp, score_Hmath;
	int SUM;
	double AVE;

	student(const string& name,
			const string& sex,
			const int& id,
			const int& age,
			const int& score_cpp,
			const int& score_Hmath) {

		this->name = name;
		this->sex = sex;
		this->id = id;
		this->age = age;
		this->score_cpp = score_cpp;
		this->score_Hmath = score_Hmath;

		SUM = score_cpp + score_Hmath;
		AVE = SUM / 2.0;
	}
};

