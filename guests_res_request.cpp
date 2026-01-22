#include "guests_res_request.h"

int Guests_Res_Request::id = 1;

Guests_Res_Request::Guests_Res_Request(int no_of_nights, Guests* people) {
    reservation_id = id;
	id++;
	this->no_of_nights = no_of_nights;
	this->people = people;
}

Guests_Res_Request::~Guests_Res_Request() {

}