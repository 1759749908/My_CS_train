#include "Park.h"

Park::Park(int total_parking_space) {
	this->init_park(total_parking_space);
	this->init_price_table();
}

bool Park::is_full() const {
	if (this->available_parking_space_guide.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int Park::get_available_parking_space() const {
	return this->free_parking_space;
}

vector<int> Park::query_available_parking_space() const {
	return vector<int>(available_parking_space_guide.cbegin(), available_parking_space_guide.cend());
}

bool Park::init_park(const int size) {
	if (size > 0) {

		this->total_parking_space = size;
		this->free_parking_space = size;

		for (int i = 1; i <= size; i++) {
			Cars.emplace(i, Car("empty", "empty", i));
			available_parking_space_guide.emplace(i);
		}

		return true;
	}
	else {
		throw "Error: The parking space must be greater than 0.";
		return false;
	}


}

bool Park::insert_car(const string& number, const string& model, const int place_id, const ptime& the_time) {
	map<int, Car>::iterator guide = Cars.find(place_id);
	if (guide->second.is_free == true) {
		guide->second.set_number(number);
		guide->second.set_model(model);
		guide->second.set_enterTime(the_time);

		available_parking_space_guide.erase(place_id);
		guide->second.is_free = false;
		guide->second.set_price(get_price(model));
		return true;
	}
	else {
		return false;
	}
}



double Park::get_price(const string& model) {
	return price_table.at(model);

}

pair<bool, double> Park::pop_car(const int place_id, const ptime& the_time) {
	map<int, Car>::iterator guide = Cars.find(place_id);

	if (guide->second.is_free == false) {
		guide->second.set_quitTime(the_time);
		double price = guide->second.charge();

		guide->second.clear();

		available_parking_space_guide.insert(place_id);


		return make_pair(true, price);
	}
	else {
		return make_pair(false, NAN);
	}


}


bool Park::init_price_table() {
	Park::price_table.clear();
	price_table.emplace("truck", 10);
	price_table.emplace("SUV", 8);
	price_table.emplace("car", 5);
	price_table.emplace("ambulances", 0);
	price_table.emplace("FireTruck", 0);
	return true;
}


const unordered_map<string, double>& Park::get_price_table() {
	return Park::price_table;
}


bool Park::is_number_available(int number) const {
	unordered_set<int>::iterator guide = available_parking_space_guide.find(number);
	if (guide != available_parking_space_guide.end()) {
		return true;
	}
	else {
		return false;
	}
}

double Park::get_price(int number) const {
	return Cars.at(number).price;
}