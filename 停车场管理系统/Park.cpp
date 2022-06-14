#include "Park.h"

Park::Park(int total_parking_space) {
	this->total_parking_space = total_parking_space;
	this->free_parking_space = total_parking_space;
	this->Cars.reserve(total_parking_space);
}

bool Park::is_full() const {
	if (this->free_parking_space > 0) {
		return false;
	}
	else {
		return true;
	}
}

int Park::get_available_parking_space() const {
	return this->free_parking_space;
}

