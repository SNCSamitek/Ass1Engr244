#pragma once
#include "date.h"
#include "information.h"
#include "guests.h"
#include <string>

class Guests {

private:
	Date checkIn;
	Date checkOut;
	Information people[4];
	short room_id;
	short no_of_people;

public: 
	Guests();
	Guests(Date checkIn, Date checkOut, Information* people, short no_of_people, short room_id);
	~Guests();
	std::string toString();
};