#pragma once
#include <string>
#include <boost/date_time.hpp>

using namespace std;
using namespace boost::posix_time;

class Car {
private:
	string number;
	string model;
	double price;

	ptime enterTime = not_a_date_time;
	ptime quitTime = not_a_date_time;
	double cost = NULL;

	bool is_enter = false;
	bool is_quit = true;

	double charge();

	int car_number = NULL;
public:
	Car(string number, string model, double price = 1.0) :number(number), model(model), price(price) {}

	bool set_number(const string& number);
	bool set_model(const string& model);
	bool set_price(const double price);

	bool enter();
	bool quit();
	time_duration stop_time() const;

};