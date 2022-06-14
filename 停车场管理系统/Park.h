#pragma once
#include "Car.h"
#include <vector>

class Park
{
private:
	int free_parking_space;
	int total_parking_space;
	vector<Car> Cars;

public:
	Park(int total_parking_space);
	bool is_full() const;
	int get_available_parking_space() const;
	vector<int> query_available_parking_space() const;

};

