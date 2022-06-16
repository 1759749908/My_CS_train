#include "Car.h"

bool Car::enter() {
	if (this->is_enter == false && this->is_quit == true) {
		this->enterTime = second_clock::local_time();
		this->is_enter = true;
		this->is_quit = false;
		this->is_free = false;
		return true;
	}
	else if (this->is_enter == true && this->is_quit == false) {
		throw "Error: The car has entered the parking lot.";
	}
	else {
		throw "Unknown error.";
	}
}

bool Car::quit() {
	if (this->is_enter == true && this->is_quit == false) {
		this->quitTime = second_clock::local_time();
		this->is_quit = true;
		this->is_enter = false;
		this->is_free = true;
		return true;
	}
	else if (this->is_enter == false && this->is_quit == true) {
		throw "Error: The car has left the parking lot";
	}
	else {
		throw "Unknown error.";
	}
}

double Car::charge() {
	if (this->enterTime != not_a_date_time && this->quitTime != not_a_date_time) {
		// double difftime (time_t end, time_t beginning);
		time_duration exist_time_duration = this->quitTime - this->enterTime;

		long long exist_time = exist_time_duration.hours() + 1;	//hours
		this->cost = exist_time * this->price;
		return this->cost;
	}
	else {
		throw "Error: enterTime or quitTime is undefined.";
	}
}

time_duration Car::stop_time() const {
	if (this->enterTime != not_a_date_time && this->quitTime != not_a_date_time) {
		time_duration stop_time_t = this->quitTime - this->enterTime;
		return stop_time_t;
	}
	else {
		throw "Error: enterTime or quitTime is undefined.";
	}
}

bool Car::set_number(const string& number) {
	this->number = number;
	return true;
}

bool Car::set_model(const string& model) {
	this->model = model;
	return true;
}

bool Car::set_price(const double price) {
	this->price = price;
	return true;
}

bool Car::set_car_number(const int number) {
	this->car_number = number;
	return true;
}

bool Car::set_enterTime(const ptime& the_time) {
	this->enterTime = the_time;
	return true;
}

bool Car::set_quitTime(const ptime& the_time) {
	this->quitTime = the_time;
	return true;
}

long long Car::stop_time_hours() const {
	return this->stop_time().hours() + 1;
}

bool Car::clear() {
	this->number = "empty";
	this->model = "empty";
	this->price = NAN;
	this->enterTime = not_a_date_time;
	this->quitTime = not_a_date_time;
	this->cost = NAN;
	this->is_enter = false;
	this->is_quit = true;
	this->car_number = NULL;
	this->is_free = true;
	return true;
}

