#include "guests_res_request.h"
#include <iostream>

int Guests_Res_Request::id = 1;

Guests_Res_Request::Guests_Res_Request(int no_of_nights, Guests* people) {
    reservation_id = id;
	id++;
	this->no_of_nights = no_of_nights;
	this->people = people;
}

Guests_Res_Request::~Guests_Res_Request() {
	delete people;
}

void Guests_Res_Request::printGuestsRequests() const{
		std::cout << this->no_of_nights << std::endl;
		std::cout << this->id << std::endl;
		std::cout << this->reservation_id << std::endl;
		people->printGuests();
}

void Guests_Res_Request::displayPeople() const{
	people->printGuests();
}
