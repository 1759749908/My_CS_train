#include <iostream>
#include <string>
#include <locale>
#include <boost/date_time.hpp>
#include <boost/format.hpp>

#include "md5.h"
#include "Park.h"
#include "CarManager.h"
#include "utils.h"

using namespace std;
using namespace boost::posix_time;
using namespace boost;

unordered_map<string, double> Park::price_table;
Park my_park(100);
CarManager admin(my_park);

bool choice_menu(int choice);
bool 停车();
bool 取车();
bool 找可用车位();
bool 停车时长统计(const CarManager& CarManager);
bool 停车时长统计_无权限版();
bool 查询价格();
bool 管理员登录();

void clear_and_show() {
	system("cls");
	wcout << setfill(L'*') << setw(128) << '\n';
	wcout << boost::wformat(L"* %-117s *\n") % L"菜单栏如下：";
	wcout << boost::wformat(L"* %-12s %-12s %-12s %-12s %-12s %-28s *") % L"1、停车" % L"2、取车" % L"3、查可用车位" % L"4、停车时长统计" % L"5、查询价格" % L"6、管理员登录" << endl;
	wcout << setfill(L'*') << setw(128) << '\n';
	wcout << boost::wformat(L"%s") % L"请输入您的选择：";
}

bool choice_menu(int choice) {
	switch (choice) {
	case 1:
		停车();
		break;
	case 2:
		取车();
		break;
	case 3:
		找可用车位();
		break;
	case 4:
		停车时长统计(admin);
		break;
	case 5:
		查询价格();
		break;
	case 6:
		管理员登录();
		break;
	default:
		return false;
	}
	return true;
}

bool 停车() {
	if (my_park.is_full()) {
		wcout << L"没位置了" << endl;
		return false;
	}

	int where_park = my_park.query_available_parking_space().front();
	string 车牌;
	string 车型;

	wcout << L"请输入车牌号：";
	cin >> 车牌;

	wcout << L"可用车型有:";
	for (const auto& i : my_park.get_price_table()) {
		wcout << string2wstring(i.first) << "\t";
	}
	wcout << L"请输入车型：";
	cin >> 车型;

	if (my_park.insert_car(车牌, 车型, where_park)) {
		double price = my_park.get_price(where_park);
		wcout << wformat(L"成功插入，你一小时要交%1%元。") % price << endl;
	}
	else {
		wcout << L"插入失败。" << endl;
	}

	return true;
}

bool 取车() {
	wcout << L"你要取哪个位置的车？" << endl;
	int choice;
	cin >> choice;

	pair<bool, double> status = my_park.pop_car(choice);
	if (status.first) {
		wcout << wformat(L"取车成功，你要交%1%元。") % status.second << endl;

	}
	else {
		wcout << L"取车失败。" << endl;
	}





	return true;
}

bool 查询价格() {
	for (const auto& i : my_park.get_price_table()) {
		wcout << string2wstring(i.first) << L"：" << i.second << "\n";
	}

	return true;
}

bool 找可用车位() {
	boost::wformat fmt(L"现在可用%d个车位");
	wcout << fmt % my_park.query_available_parking_space().size() << '\n';

	/*
	wcout << fmt % my_park.get_available_parking_space() << endl;
	for (auto i : my_park.query_available_parking_space()) {
		cout << i << '\t';
	}
	cout << endl;
	*/

	return true;
}

bool 停车时长统计_无权限版() {
	wcout << L"该功能仅登录管理员账户后可用，请登录" << '\n';
	return true;
}

bool 管理员登录() {
	string id, key;
	wcout << L"请输入管理员用户名：\n";
	cin >> id;
	wcout << L"请输入管理员密码：\n";
	cin >> key;

	bool status = admin.login(id, key);

	if(status) {
		wcout << L"登录成功\n";
	}
	else {
		wcout << L"登录失败\n";
	}
	return status;
}

int main()
{

	string str = "!Admin123";
	cout << "md5 of this string: " << md5(str) << endl;

	wcin.imbue(std::locale("chs"));
	wcout.imbue(std::locale("chs"));

back:
	clear_and_show();

	int choice;
	cin >> choice;
	choice_menu(choice);
	system("pause");
	goto back;
}


bool 停车时长统计(const CarManager& CarManager) {
	if (CarManager.get_is_login()) {
		wcout << L"总共收费" << CarManager.get_total_money() << "元。\n";
	}
	else {
		停车时长统计_无权限版();
	}
	return true;
}