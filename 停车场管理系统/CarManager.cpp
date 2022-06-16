#include "CarManager.h"

CarManager::CarManager(const Park& myPark) : myPark(myPark) {}

bool CarManager::login(const string& id, const string& key) {
	string true_id = "admin";
	string true_key = "59d51b5cb69c829ea5bfe77e38a1522e";
	if (id == true_id && md5(key) == true_key) {
		is_login = true;
		return true;
	}
	else {
		return false;
	}
}

bool CarManager::停车时长统计_有权限版() {
	for (const auto& i : this->myPark.Cars) {
		if (i.second.is_free == false) {
			cout << i.second.number << "\t" << i.second.model << "\t" << to_simple_string(i.second.stop_time()) << "\n";
		}
	}
	return true;
}

double CarManager::get_total_money() const {
	return this->myPark.total_money;
}

bool CarManager::get_is_login() const {
	return this->is_login;
}