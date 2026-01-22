#pragma once
#include "guests_res_request.h"
#include <string>

class Reservation_Manager {

private:
	const static int max_no_of_nights = 7;
	const static int no_of_rooms = 20;
	Guests_Res_Request *arr;
<<<<<<< HEAD
	int reservation_table [max_no_of_nights][no_of_rooms] = {};
=======
	int screw_this_assignment[max_no_of_nights][no_of_rooms];
>>>>>>> 27332c46d1750ce7956e9bc2b657c8f87db7c7ec
public: 
	Reservation_Manager();
	~Reservation_Manager();
};