#include "guests_res_request.h"
#include <iostream>

//constructors and destructor ----------------------------------------------------------------------------
int Guests_Res_Request::id = 1;
Guests_Res_Request::Guests_Res_Request(){
	id++;
	reservation_id = 0;
	no_of_nights = 0;
	people = nullptr;
}

Guests_Res_Request::Guests_Res_Request(int numnights, Guests* ppl) {
    reservation_id = id;
	id++;
	no_of_nights = numnights;
	this->people = ppl;
}

Guests_Res_Request::~Guests_Res_Request() {
	delete people;
}
//-------------------------------------------------------------------------------------------

//setters -----------------------------------------------------------------------------------
void  Guests_Res_Request::set_no_of_nights(int numnights){
		no_of_nights = numnights;
	}

void  Guests_Res_Request::set_reservation_id(int resId) {
		reservation_id = resId;
	}
//-------------------------------------------------------------------------------------------

void Guests_Res_Request::printGuestsRequests() const{
		std::cout << this->no_of_nights << std::endl;
		std::cout << this->reservation_id << std::endl;

		people->printGuests();
}


