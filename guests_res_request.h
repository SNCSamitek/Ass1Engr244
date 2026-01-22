#pragma once
#include "guests.h"
#include <string>

class Guests_Res_Request {

private:
	static int id;
	int reservation_id;
	int no_of_nights;
	Guests* people;

public: 
	Guests_Res_Request(int no_of_nights, Guests* people);
	~Guests_Res_Request();
};