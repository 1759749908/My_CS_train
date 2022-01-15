#include "my_func.h"

bool print(const vector<People>& people) {
	for (const auto& i : people) {
		cout << i << endl;
	}
	return 0;
}

ostream& operator<<(ostream& os, const People& person) {
	for (const auto& i : person.db) {
		os << i.first << "：" << i.second << endl;
	}
	return os;
}

vector<vector<string>> read_profile(const string& address) {
	ifstream ifs(address);
	if (!(ifs.is_open())) {
		return vector<vector<string>>();
	}
	vector<vector<string>> ans;
	string temp_data;
	while (getline(ifs, temp_data)) {
		vector<string> temp_vec = split(temp_data, "—");
		vector<string> temp_vec_2 = split(temp_vec[1], ",");
		temp_vec_2.emplace(temp_vec_2.begin(), temp_vec[0]);
		ans.emplace_back(temp_vec_2);
	}
	return ans;
}

bool input(People& person, vector<pair<string, string>>& user_input) {
	for (const auto& i : user_input) {
		person.add_db(i.first, i.second);
	}
	return 0;
}

void dbsearch(database& db) {
	cout << "你想查询什么？1—所有属性，2—部分属性，3—直接输出所有人" << endl;
	int choice;
	if (cin >> choice) {
		switch (choice)
		{
		case 1:
		{
			string keyword;
			cout << "请输入要查找的值" << endl;
			cin >> keyword;
			print(db.search(keyword));
			break;
		}
		case 2:
		{
			string key1;
			string key2;
			cout << "请输入要查找的属性名" << endl;
			cin >> key1;
			cout << "请输入要查找的值" << endl;
			cin >> key2;
			print(db.multi_search(key1, key2));
			break;
		}
		case 3:
			print(db.ouput_all());
			break;
		default:
			break;
		}

	}
	else {
		cout << "输入非法" << endl;
	}
}

void dbadd(vector<vector<string>>& Types, database& db) {
	cout << "目前一共有以下人员，请选择性添加" << endl;
	int n = Types.size();
	for (int i = 0; i < n; i++) {
		cout << i << "——" << Types[i][0] << endl;
	}
	cout << "添加哪位?" << endl;
	int choice;
	cin >> choice;
	if (choice >= 0 && choice < n) {
		cout << "请按照顺序输入以下内容：" << endl;
		for (auto it = Types[choice].begin() + 1; it != Types[choice].end(); it++) {
			cout << *it << "  ";
		}
		cout << endl;
		vector<pair<string, string>> input_pair;
		input_pair.resize(Types[choice].size());
		input_pair[0].first = "类型";
		input_pair[0].second = Types[choice][0];
		for (size_t i = 1; i < input_pair.size(); i++) {
			input_pair[i].first = Types[choice][i];
			cin >> input_pair[i].second;
		}
		db.add_people(input_pair);
		cout << "添加成功" << endl;
	}
	else {
		cout << "非法输入" << endl;
	}
}

void my_delete(database& db) {
	string ID;
	cout << "请输入要删除的人的ID" << endl;
	cin >> ID;
	db.delete_people(ID);
	cout << "删除成功" << endl;
}

void reload(database& db) {
	cout << "请输入数据库路径（输入 N 表示默认）" << endl;
	string address;
	cin >> address;
	if (address == "N") {
		if (db.read()) {
			cout << "加载失败" << endl;
		}
		else {
			cout << "加载成功" << endl;
		}
	}
	else
	{
		if (db.read(address)) {
			cout << "加载失败" << endl;
		}
		else {
			cout << "加载成功" << endl;
		}
	}
}

void dbsave(database& db) {
	cout << "请输入数据库保存路径（输入 N 表示默认）" << endl;
	string address;
	cin >> address;
	if (address == "N") {
		if (db.save()) {
			cout << "保存失败" << endl;
		}
		else {
			cout << "保存成功" << endl;
		}
	}
	else
	{
		if (db.save(address)) {
			cout << "保存失败" << endl;
		}
		else {
			cout << "保存成功" << endl;
		}
	}
}

void change(database& db) {
	cout << "请输入你要修改的人的ID" << endl;
	string ID;
	string info_1;
	string info_2;
	cin >> ID;
	cout << *db.find_by_ID(ID) << endl;
	cout << "以上是此人信息，请输入要修改的属性" << endl;
	cin >> info_1;
	cout << "请输入修改后的值" << endl;
	cin >> info_2;
	if (db.change(ID, make_pair(info_1, info_2))) {
		cout << "修改失败" << endl;
	}
	else {
		cout << "修改成功" << endl;
	}
}

void statistics(database& db) {
	int people_number;
	int gender_boy = 0;
	int gender_girl = 0;
	people_number = db.people.size();
	map<string, int> people_type;

	for (auto it = db.people.begin(); it != db.people.end(); it++) {
		if (it->match_some("gender", "男")) {
			gender_boy++;
		}
		if (it->match_some("gender", "女")) {
			gender_girl++;
		}
		++people_type[it->match_index("类型")];
	}


	cout << "总共" << people_number << "个人" << endl;
	cout << "男的有" << gender_boy << "个人" << endl;
	cout << "女的有" << gender_girl << "个人" << endl;

	for (auto it = people_type.begin(); it != people_type.end(); it++) {
		cout << it->first << "有" << it->second << "个" << endl;
	}
}

void add_people_type(vector<vector<string>>& Types, database& db) {
	cout << "目前一共有以下人员" << endl;
	int n = Types.size();
	for (int i = 0; i < n; i++) {
		cout << i << "——" << Types[i][0] << endl;
	}
	vector<string> people_type;
	string user_ans;

	cout << "请输入要添加的人类型" << endl;
	cin >> user_ans;
	people_type.emplace_back(user_ans);
	cout << "需要继承吗？(Y/N，默认N)" << endl;
	goto out;
	back_out:
	cout << "还需要继承吗？(Y/N，默认N)" << endl;
	out:

	cin >> user_ans;
	if (user_ans == "Y") {
		cout << "需要继承哪些？输入序号" << endl;
		int choice;
		cin >> choice;
		if (choice >= 0 && choice < n) {
			for (auto it = Types[choice].begin() + 1; it != Types[choice].end();it++) {
				safe_add(people_type, *it);
			}
			cout << "添加成功" << endl;
		}
		else {
			cout << "非法输入" << endl;
		}
		goto back_out;
	}

	cout << "需要直接手动添加吗？(Y/N，默认N)" << endl;
	cin >> user_ans;
	if (user_ans == "Y") {
		cout << "需要添加多少属性？" << endl;
		int number;
		cin >> number;
		if (number >= 0) {
			string need_add;
			cout << "需要添加的属性名，空格分割" << endl;
			for (int i = 0; i < number; i++) {
				cin >> need_add;
				safe_add(people_type, need_add);
			}
			cout << "添加成功" << endl;
		}
		else {
			cout << "非法输入" << endl;
		}
	}
	Types.emplace_back(people_type);
}

void safe_add(vector<string>& people_type, string add_type) {
	for (const auto& i : people_type) {
		if (i == add_type) {
			return;
		}
	}
	people_type.emplace_back(add_type);
}