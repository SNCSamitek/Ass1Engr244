#pragma once
#include "date.h"
#include "information.h"
#include "guests.h"
#include <string>

class Guests_Res_Request {

private:
	static int id;
	int reservation_id;
	int number_of_nights;
	Guests a;

public: 
	Guests_Res_Request();
	~Guests_Res_Request();
};