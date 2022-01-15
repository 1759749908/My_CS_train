#include <iostream>
#include <iomanip>
#include <vector>
#include "database.h"
#include "my_func.h"
using namespace std;

void show(vector<vector<string>>& Types, database& db) {
    cout << "******************************************" << '\n'
        << "**" << setw(30) << "欢迎进入人员管理系统" << setw(10) << "**" << '\n' //"欢迎进入人员管理系统"刚刚好20个字符
        << "**" << setw(30) << "查询请输入：1" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "增加请输入：2" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "删除请输入：3" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "修改请输入：4" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "统计请输入：5" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "重新加载数据库请输入：6" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "添加人员类型请输入：7" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "保存请输入：8" << setw(10) << "**" << '\n'
        << "**" << setw(30) << "退出请输入：9" << setw(10) << "**" << '\n'
        << "******************************************" << '\n';
    int choice;
    if (cin >> choice) {
        switch (choice)
        {
        case 1:
            dbsearch(db);
            break;
        case 2:
			dbadd(Types, db);
            break;
        case 3:
            my_delete(db);
            break;
        case 4:
            change(db);
            break;
        case 5:
            statistics(db);
            break;
        case 6:
            reload(db);
            break;
        case 7:
			add_people_type(Types, db);
            break;
        case 8:
            dbsave(db);
            break;
        case 9:
            exit(0);
            break;
        default:
            break;
        }
    }
    else {
        cout << "非法操作" << endl;
    }

}

int main()
{
    vector<vector<string>> Types = read_profile();

    database people;
    people.read();

    while (true) {
		show(Types, people);
    }
    
    people.save();

}