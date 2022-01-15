#pragma once
#include <utility>
#include <vector>
#include <string>
using namespace std;

class People {
public:
	bool add_db(const string& key1, const string& key2);
	bool delete_db(const string& key);
	bool change_db(const string& key1, const string& key2);
	bool match_all(const string& keyword) const;
	string match_index(const string& keyword) const;
	bool match_some(const string& key_column, const string& keyword) const;
	inline vector<pair<string, string>> get() const;

	vector<pair<string, string>> db;
	//这里用map或者unordered_map也许更好，不过数据小懒得用了，而且顺序会被改。
};