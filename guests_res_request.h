#pragma once
#include "guests.h"
#include <string>
#include <iostream>

class Guests_Res_Request {

private:
	static int id;
	int reservation_id;
	int no_of_nights;
	Guests* people;

public: 
	//constructors & destructors
	Guests_Res_Request();
	Guests_Res_Request(int numnights, Guests* ppl);
	~Guests_Res_Request();

	//getters 
	inline const Guests* getPeople()const{return people;}
	inline int get_no_of_nights() const{return no_of_nights;}
	inline int get_reservation_id() const{return reservation_id;}

	//setters
	void set_no_of_nights(int numnights);
	void set_reservation_id(int resId);

	//other
	void printGuestsRequests() const;
};