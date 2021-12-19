#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Book {
public:
	string bookname;
	double price;
	int number;

	Book(const string&, const double&, const int&);

	void display() const;
	void borrow();
	void restore();
};

void display_stock(const vector<Book>&);
void search_book(const vector<Book>&);
void borrow_book(vector<Book>&);
void give_back_book(vector<Book>&);
void add_book(vector<Book>&);

int main() {
	//cin.sync_with_stdio(false);
	vector<Book> library;
	library.emplace_back(Book("数学之美", 35, 275));
	library.emplace_back(Book("浪潮之巅", 39, 287));
	library.emplace_back(Book("计算之魂", 55, 27));
	library.emplace_back(Book("三国演义", 20, 685));
	library.emplace_back(Book("五年单身，三年当狗", 10, 185));
	library.emplace_back(Book("中国共产党简史", 20, 927));
	library.emplace_back(Book("文明之光", 30, 278));
	library.emplace_back(Book("编译系统", 60, 627));
	library.emplace_back(Book("从一到无穷大", 40, 625));
	library.emplace_back(Book("影响力", 40, 157));
	library.emplace_back(Book("C++从入门到放弃", 9.9, 278));
	library.emplace_back(Book("中华人民共和国刑法", 56, 378));
	library.emplace_back(Book("茶馆", 49, 278));
	library.emplace_back(Book("边城", 32, 72));
	library.emplace_back(Book("活着", 38, 682));

	int choice;
	while (true) {
		cout <<
			"***********************        欢迎进入图书馆系统        ***********************\n" <<
			"操作说明：0-退出系统；1-显示库存；2-查询图书；3-借阅图书；4-归还图书；5-增加图书\n" <<
			"请输入操作：";

		if (!(cin >> choice)) {
			cout << "输入非法，请重试" << endl;
		}

		switch (choice) {
		case 0:
			exit(0);
		case 1:
			printf("********************************************************************************\n");
			display_stock(library);
			break;
		case 2:
			printf("********************************************************************************\n");
			search_book(library);
			break;
		case 3:
			printf("********************************************************************************\n");
			borrow_book(library);
			break;
		case 4:
			printf("********************************************************************************\n");
			give_back_book(library);
			break;
		case 5:
			printf("********************************************************************************\n");
			add_book(library);
			break;
		default:
			printf("********************************************************************************\n");
			printf("无效操作，请重试。\n");
		}
	}
}

void display_stock(const vector<Book>& library) {
	for (vector<Book>::const_iterator it = library.cbegin(); it != library.cend(); it++) {
		it->display();
	}
}

void search_book(const vector<Book>& library) {
	string key;
	printf("请输入您要查找的书的名字（不带书名号）：");
	cin >> key;
	for (vector<Book>::const_iterator it = library.cbegin(); it != library.cend(); it++) {
		if (it->bookname == key) {
			it->display();
			return;
		}
	}
	printf("查无此书\n");
}

void borrow_book(vector<Book>& library) {
	string key;
	printf("请输入您要借的书的名字（不带书名号）：");
	cin >> key;
	for (vector<Book>::iterator it = library.begin(); it != library.end(); it++) {
		if (it->bookname == key) {
			it->borrow();
			return;
		}
	}
	printf("查无此书\n");
}

void give_back_book(vector<Book>& library) {
	string key;
	printf("请输入您要还的书的名字（不带书名号）：");
	cin >> key;
	for (vector<Book>::iterator it = library.begin(); it != library.end(); it++) {
		if (it->bookname == key) {
			it->restore();
			return;
		}
	}
	printf("查无此书\n");
}

void add_book(vector<Book>& library) {
	string bookname;
	double price;
	int number;

	printf("请输入您要添加的书的名字（不带书名号）：");
	cin.clear();
	cin.ignore();
	//清空缓冲区
	getline(cin, bookname);

	printf("请输入您要添加的书的价格：");
	if (!(cin >> price)) {
		printf("输入非法，填加失败\n");
		cin.clear();
		cin.ignore();
		//清空缓冲区
		return;
	}

	printf("请输入您要添加的书的库存：");
	if (!(cin >> number)) {
		printf("输入非法，填加失败\n");
		cin.clear();
		cin.ignore();
		//清空缓冲区
		return;
	}

	library.emplace_back(Book(bookname, price, number));
	printf("填加成功\n");


}

Book::Book(const string& bookname, const double& price, const int& number) {
	this->bookname = bookname;
	this->price = price;
	this->number = number;
}

void Book::display() const {
	cout << "书名：《" << bookname << "》" << setw(40 - bookname.size()) << "价格：" << price << "\t\t库存：" << number << endl;
}

void Book::borrow() {
	if (number > 0) {
		--number;
		printf("借出成功，《%s》的当前库存为：%d\n", bookname.c_str(), number);
	}
	else printf("借出失败，《%s》的当前库存为：%d\n", bookname.c_str(), number);
}

void Book::restore() {
	++number;
	printf("存入成功，《%s》的当前库存为：%d\n", bookname.c_str(), number);
}