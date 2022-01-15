#pragma once
#include "People.h"
#include "usefulFunc.h"
#include <string>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

class database
{
public:
	bool save(const string& address = "./people.db");
	bool read(const string& address = "./people.db");
	bool add_people(const vector<pair<string, string>>& in);
	bool delete_people(const string& key_ID); //只有ID是不能重复的
	bool change(const string& key_ID, const pair<string, string>& in);

	list<People>::iterator find_by_ID(const string& key_ID);
	vector<People> multi_search(const string& key1, const string& key2) const;
	vector<People> search(const string& keyword) const;
	vector<People> ouput_all() const;
	list<People> people;
};

