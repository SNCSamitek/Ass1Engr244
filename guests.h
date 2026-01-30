#pragma once
#include "date.h"
#include "information.h"
#include <string>
#include <iostream>

class Guests {

private:
	Date checkIn;
	Date checkOut;
	Information people[4];
	short room_id;
	short no_of_people;

public: 
	//constructors & desctructors
	Guests();
	Guests(Guests const &obj);
	Guests(Date checkIn, Date checkOut, Information* people, short no_of_people, short room_id);
	~Guests();
	std::string toString();
	void printGuests();

	//getters
	inline const Information* getInformation() const {return people;}
	inline const Date& getCheckIn() const {return checkIn;}
	inline const Date& getCheckOut() const {return checkOut;}
	inline int getNo_of_people() const {return no_of_people;}
	inline int getRoomId() const {return room_id;}

	//setters
	void setCheckIn(Date& d);
	void setCheckOut(Date& d);
	void setNo_of_people(int np);
	void setRoomId(int ri);
};