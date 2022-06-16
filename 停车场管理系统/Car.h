#pragma once
#include <string>
#include <boost/date_time.hpp>

using namespace std;
using namespace boost::posix_time;

class Car {
	friend class Park;
	friend class CarManager;

private:
	string number;
	string model;
	double price = NAN;

	ptime enterTime = not_a_date_time;
	ptime quitTime = not_a_date_time;
	double cost = NAN;

	bool is_enter = false;
	bool is_quit = true;
	bool is_free = true;

	double charge();

	int car_number = NULL;
public:
	Car(string number, string model, int car_number) :number(number), model(model), car_number(car_number) {}

	bool set_number(const string& number);
	bool set_model(const string& model);
	bool set_price(const double price);
	bool set_car_number(const int number);

	bool set_enterTime(const ptime& the_time);
	bool set_quitTime(const ptime& the_time);

	bool clear();

	bool enter();
	bool quit();
	time_duration stop_time() const;
	long long stop_time_hours() const;

};