#include "database.h"

bool database::save(const string& address) {
	ofstream ofs(address);	//覆盖
	if (!ofs.is_open()) {
		return 1;
	}
	for (const auto& i : people) {
		for (const auto& j : i.db) {
			ofs << j.first << "\x01\x02\x03\x04" << j.second << "\x01\x02\x03\x04";	//用不可打印的控制字符分离
		}
		ofs << '\n';
	}
	ofs.close();
	return 0;
}

bool database::read(const string& address) {
	ifstream ifs(address);
	if (!(ifs.is_open())) {
		return 1;
	}
	string temp_data;
	people.clear();
	while (getline(ifs, temp_data)) {
		auto temp_db = split(temp_data, "\x01\x02\x03\x04");
		temp_db.pop_back();
		People person_temp;
		for (size_t i = 0; i < temp_db.size(); i += 2) {
			person_temp.add_db(temp_db[i], temp_db[i + 1]);
		}
		people.emplace_back(person_temp);
	}
	return 0;
}

list<People>::iterator database::find_by_ID(const string& key_ID) {
	for (auto it = people.begin(); it != people.end(); it++) {
		for (auto& j : it->db) {
			if (j.first == "ID") {
				if (j.second == key_ID) {
					return it;
				}
				else {
					break;
				}
			}
		}
	}
	return people.end();
}

bool database::delete_people(const string& key_ID) {
	auto it = find_by_ID(key_ID);
	if (it == people.end()) {
		return 1;
	}
	else {
		people.erase(it);
		return 0;
	}
}

vector<People> database::search(const string& keyword) const {
	vector<People> ans;
	for (const auto& i : people) {
		if (i.match_all(keyword)) {
			ans.emplace_back(i);
		}
	}
	return ans;
}

vector<People> database::multi_search(const string& key1, const string& key2) const {
	vector<People> ans;
	for (const auto& i : people) {
		if (i.match_some(key1, key2)) {
			ans.emplace_back(i);
		}
	}
	return ans;
}

bool database::add_people(const vector<pair<string, string>>& in) {
	People person_temp;
	for (const auto& i : in) {
		person_temp.add_db(i.first, i.second);
	}
	people.emplace_back(person_temp);
	return 0;
}

bool database::change(const string& key_ID, const pair<string, string>& in) {
	auto it = find_by_ID(key_ID);
	if (it == people.end()) {
		return 1;
	}
	else {
		return it->change_db(in.first, in.second);
	}
}

vector<People> database::ouput_all() const {
	return vector<People>(people.begin(), people.end());
}