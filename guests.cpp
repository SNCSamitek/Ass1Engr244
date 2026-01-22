#include "guests.h"
#include <sstream>

Guests::Guests() {
	checkIn = Date();
	checkOut = Date();
	no_of_people = 0;
	room_id = 0;
}

Guests::Guests(Guests const &obj) {
	this->checkIn = obj.checkIn;
	this->checkOut = obj.checkOut;
	this->no_of_people = no_of_people;
	if (obj.people != nullptr) {
		for (int i = 0; i < obj.no_of_people; i++) {
			this->people[i] = obj.people[i];
		}
	}
	this->room_id = room_id;
}

Guests::Guests(Date checkIn, Date checkOut, Information* people, short no_of_people, short room_id) {
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->no_of_people = no_of_people;
	if (people != nullptr) {
		for (int i = 0; i < no_of_people; i++) {
			this->people[i] = people[i];
		}
	}
	this->checkIn = checkIn;
}

Guests::~Guests() {
	
}

std::string Guests::toString() {
	std::ostringstream value;
    value << "\nCheck in date: " << checkIn.toString() << " --- Check out date" << checkOut.toString() << " --- Room ID " << room_id << '\n';
	for (int i = 0; i < no_of_people; i++) {
		value << people[i].toString();
	}
	value << "\n";
	return value.str();
}