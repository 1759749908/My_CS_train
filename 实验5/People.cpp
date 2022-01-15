#include "People.h"

bool People::add_db(const string& key1, const string& key2)	{
	db.emplace_back(key1, key2);
	return 0;
}

bool People::delete_db(const string& key) {
	for (auto it = db.begin(); it != db.end(); it++) {
		if (key == (*it).first) {
			db.erase(it);
			return 0;
		}
	}
	return 1;
}

bool People::match_all(const string& keyword) const {
	for (const auto& i : db) {
		if (i.second == keyword) {
			return 1;
		}
	}
	return 0;
}

bool People::match_some(const string& key, const string& keyword) const {
	for (const auto& i : db) {
		if (i.first == key && i.second == keyword) {
			return 1;
		}
	}
	return 0;
}

inline vector<pair<string, string>> People::get() const{
	return db;
}

bool People::change_db(const string& key1, const string& key2) {
	for (auto& i : db) {
		if (i.first == key1) {
			i.second = key2;
			return 0;
		}
	}
	return 1;
}

string People::match_index(const string& keyword) const {
	for (const auto& i : db) {
		if (i.first == keyword) {
			return i.second;
		}
	}
	return "";
}