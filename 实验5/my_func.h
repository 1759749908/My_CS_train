#pragma once
#include "People.h"
#include "database.h"
#include "usefulFunc.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;


vector<vector<string>> read_profile(const string& address = "./profile.txt");
vector<string> save_profile(const string& address = "./profile.txt");

bool input(People& person, vector<pair<string, string>>& user_input);
bool print(const vector<People>& people);

ostream& operator<<(ostream& os, const People& person);

void dbsearch(database& db);
void dbadd(vector<vector<string>>& Types, database& db);
void my_delete(database& db);
void reload(database& db);
void dbsave(database& db);
void change(database& db);
void statistics(database& db);
void add_people_type(vector<vector<string>>& Types, database& db);
void safe_add(vector<string>& people_type, string add_type);