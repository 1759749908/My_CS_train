#pragma once
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Park.h"
#include "md5.h"

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std;

class CarManager {
private:
	const Park& myPark;
	string id = "admin";
	string key;
	bool is_login = false;
public:
	bool get_is_login() const;
	CarManager(const Park& myPark);
	bool login(const string& id, const string& key);
	double get_total_money() const;
	bool 停车时长统计_有权限版();
};