#pragma once
#include "Car.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <map>
#include <utility> //pair
#include "utils.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace boost::posix_time;

class Park
{
	friend int main();
	friend class CarManager;
private:
	static unordered_map<string, double> price_table;

	static double get_price(const string& model);
	bool init_park(const int size);

	int free_parking_space;
	int total_parking_space;

	double total_money = 0.0;
	map<int, Car> Cars;
	unordered_set<int> available_parking_space_guide;

public:
	Park(int total_parking_space);

	static bool init_price_table();
	static const unordered_map<string, double>& get_price_table();

	double get_price(int number) const;
	bool is_number_available(int number) const;

	bool is_full() const;
	int get_available_parking_space() const;
	vector<int> query_available_parking_space() const;

	bool insert_car(const string& number, const string& model, const int place_id, const ptime& the_time = second_clock::local_time());
	pair<bool,double> pop_car(const int place_id, const ptime& the_time = second_clock::local_time());
};

