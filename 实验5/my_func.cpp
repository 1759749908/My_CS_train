#include "my_func.h"

bool print(const vector<People>& people) {
	for (const auto& i : people) {
		cout << i << endl;
	}
	return 0;
}

ostream& operator<<(ostream& os, const People& person) {
	for (const auto& i : person.db) {
		os << i.first << "��" << i.second << endl;
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
		vector<string> temp_vec = split(temp_data, "��");
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
	cout << "�����ѯʲô��1���������ԣ�2���������ԣ�3��ֱ�����������" << endl;
	int choice;
	if (cin >> choice) {
		switch (choice)
		{
		case 1:
		{
			string keyword;
			cout << "������Ҫ���ҵ�ֵ" << endl;
			cin >> keyword;
			print(db.search(keyword));
			break;
		}
		case 2:
		{
			string key1;
			string key2;
			cout << "������Ҫ���ҵ�������" << endl;
			cin >> key1;
			cout << "������Ҫ���ҵ�ֵ" << endl;
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
		cout << "����Ƿ�" << endl;
	}
}

void dbadd(vector<vector<string>>& Types, database& db) {
	cout << "Ŀǰһ����������Ա����ѡ�������" << endl;
	int n = Types.size();
	for (int i = 0; i < n; i++) {
		cout << i << "����" << Types[i][0] << endl;
	}
	cout << "�����λ?" << endl;
	int choice;
	cin >> choice;
	if (choice >= 0 && choice < n) {
		cout << "�밴��˳�������������ݣ�" << endl;
		for (auto it = Types[choice].begin() + 1; it != Types[choice].end(); it++) {
			cout << *it << "  ";
		}
		cout << endl;
		vector<pair<string, string>> input_pair;
		input_pair.resize(Types[choice].size());
		input_pair[0].first = "����";
		input_pair[0].second = Types[choice][0];
		for (size_t i = 1; i < input_pair.size(); i++) {
			input_pair[i].first = Types[choice][i];
			cin >> input_pair[i].second;
		}
		db.add_people(input_pair);
		cout << "��ӳɹ�" << endl;
	}
	else {
		cout << "�Ƿ�����" << endl;
	}
}

void my_delete(database& db) {
	string ID;
	cout << "������Ҫɾ�����˵�ID" << endl;
	cin >> ID;
	db.delete_people(ID);
	cout << "ɾ���ɹ�" << endl;
}

void reload(database& db) {
	cout << "���������ݿ�·�������� N ��ʾĬ�ϣ�" << endl;
	string address;
	cin >> address;
	if (address == "N") {
		if (db.read()) {
			cout << "����ʧ��" << endl;
		}
		else {
			cout << "���سɹ�" << endl;
		}
	}
	else
	{
		if (db.read(address)) {
			cout << "����ʧ��" << endl;
		}
		else {
			cout << "���سɹ�" << endl;
		}
	}
}

void dbsave(database& db) {
	cout << "���������ݿⱣ��·�������� N ��ʾĬ�ϣ�" << endl;
	string address;
	cin >> address;
	if (address == "N") {
		if (db.save()) {
			cout << "����ʧ��" << endl;
		}
		else {
			cout << "����ɹ�" << endl;
		}
	}
	else
	{
		if (db.save(address)) {
			cout << "����ʧ��" << endl;
		}
		else {
			cout << "����ɹ�" << endl;
		}
	}
}

void change(database& db) {
	cout << "��������Ҫ�޸ĵ��˵�ID" << endl;
	string ID;
	string info_1;
	string info_2;
	cin >> ID;
	cout << *db.find_by_ID(ID) << endl;
	cout << "�����Ǵ�����Ϣ��������Ҫ�޸ĵ�����" << endl;
	cin >> info_1;
	cout << "�������޸ĺ��ֵ" << endl;
	cin >> info_2;
	if (db.change(ID, make_pair(info_1, info_2))) {
		cout << "�޸�ʧ��" << endl;
	}
	else {
		cout << "�޸ĳɹ�" << endl;
	}
}

void statistics(database& db) {
	int people_number;
	int gender_boy = 0;
	int gender_girl = 0;
	people_number = db.people.size();
	map<string, int> people_type;

	for (auto it = db.people.begin(); it != db.people.end(); it++) {
		if (it->match_some("gender", "��")) {
			gender_boy++;
		}
		if (it->match_some("gender", "Ů")) {
			gender_girl++;
		}
		++people_type[it->match_index("����")];
	}


	cout << "�ܹ�" << people_number << "����" << endl;
	cout << "�е���" << gender_boy << "����" << endl;
	cout << "Ů����" << gender_girl << "����" << endl;

	for (auto it = people_type.begin(); it != people_type.end(); it++) {
		cout << it->first << "��" << it->second << "��" << endl;
	}
}

void add_people_type(vector<vector<string>>& Types, database& db) {
	cout << "Ŀǰһ����������Ա" << endl;
	int n = Types.size();
	for (int i = 0; i < n; i++) {
		cout << i << "����" << Types[i][0] << endl;
	}
	vector<string> people_type;
	string user_ans;

	cout << "������Ҫ��ӵ�������" << endl;
	cin >> user_ans;
	people_type.emplace_back(user_ans);
	cout << "��Ҫ�̳���(Y/N��Ĭ��N)" << endl;
	goto out;
	back_out:
	cout << "����Ҫ�̳���(Y/N��Ĭ��N)" << endl;
	out:

	cin >> user_ans;
	if (user_ans == "Y") {
		cout << "��Ҫ�̳���Щ���������" << endl;
		int choice;
		cin >> choice;
		if (choice >= 0 && choice < n) {
			for (auto it = Types[choice].begin() + 1; it != Types[choice].end();it++) {
				safe_add(people_type, *it);
			}
			cout << "��ӳɹ�" << endl;
		}
		else {
			cout << "�Ƿ�����" << endl;
		}
		goto back_out;
	}

	cout << "��Ҫֱ���ֶ������(Y/N��Ĭ��N)" << endl;
	cin >> user_ans;
	if (user_ans == "Y") {
		cout << "��Ҫ��Ӷ������ԣ�" << endl;
		int number;
		cin >> number;
		if (number >= 0) {
			string need_add;
			cout << "��Ҫ��ӵ����������ո�ָ�" << endl;
			for (int i = 0; i < number; i++) {
				cin >> need_add;
				safe_add(people_type, need_add);
			}
			cout << "��ӳɹ�" << endl;
		}
		else {
			cout << "�Ƿ�����" << endl;
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