#pragma once
#include "date.h"
#include "information.h"
#include "guests.h"
#include "guests_res_request.h"
#include <string>
#include <vector>

class Reservation_Manager {

private:
	const static int max_no_of_nights = 7;
	const static int no_of_rooms = 20;
	std::vector <Guests_Res_Request*> arr;
	int reservation_table [max_no_of_nights][no_of_rooms];
public: 
	Reservation_Manager();
	~Reservation_Manager();

	void displayDetails(int id);
	void cancelReservation(int id);
	int processReservation(Guests_Res_Request* request);
};