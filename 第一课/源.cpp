#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct 总分升序 {
	bool operator()(const Person& A, const Person& B) {
		return A.sum > B.sum;
	}
};

struct 总分降序 {
	bool operator()(const Person& A, const Person& B) {
		return A.sum < B.sum;
	}
};

struct 平均分升序 {
	bool operator()(const Person& A, const Person& B) {
		return A.average > B.average;
	}
};

struct 平均分降序 {
	bool operator()(const Person& A, const Person& B) {
		return A.average < B.average;
	}
};

struct 数学分升序 {
	bool operator()(const Person& A, const Person& B) {
		return A.average > B.average;
	}
};

struct 数学分降序 {
	bool operator()(const Person& A, const Person& B) {
		return A.average < B.average;
	}
};
struct 英语分升序 {
	bool operator()(const Person& A, const Person& B) {
		return A.average > B.average;
	}
};

struct 英语分降序 {
	bool operator()(const Person& A, const Person& B) {
		return A.average < B.average;
	}
};

struct 物理分升序 {
	bool operator()(const Person& A, const Person& B) {
		return A.PH > B.PH;
	}
};

struct 物理分降序 {
	bool operator()(const Person& A, const Person& B) {
		return A.PH < B.PH;
	}
};

struct 学号升序 {
	bool operator()(const Person& A, const Person& B) {
		return A.ID > B.ID;
	}
};

struct 学号降序 {
	bool operator()(const Person& A, const Person& B) {
		return A.ID < B.ID;
	}
};

class Person {
public:
	string name;
	double ID = 0;

	double MT = 0;
	double EN = 0;
	double PH = 0;

	double sum;
	double average;

	Person(
		const string& name,
		const double& ID,
		const double& MT,
		const double& EN,
		const double& PH)
	{
		this->name = name;
		this->ID = ID;
		this->MT = MT;
		this->EN = EN;
		this->PH = PH;

		sum = MT + EN + PH;
		average = (MT + EN + PH) / 3;
	}
};



int main() {
	Person A("张三", 1, 50, 95, 64);


}

