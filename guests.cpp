#include "guests.h"
#include <sstream>

//constructors and deconstructor ----------------------------------------------------------------------------
Guests::Guests() {
	checkIn = Date();
	checkOut = Date();
	no_of_people = 0;
	room_id = 0;
}

Guests::Guests(Guests const &obj) {
	this->checkIn = obj.checkIn;
	this->checkOut = obj.checkOut;
	this->no_of_people = obj.no_of_people;
	for (int i = 0; i < obj.no_of_people; i++) {
		this->people[i] = obj.people[i];
	}
	this->room_id = obj.room_id;
}

Guests::Guests(Date checkIn, Date checkOut, Information* people, short no_of_people, short room_id) {
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->no_of_people = no_of_people;
	if (people != nullptr) {
		for (int i = 0; i < no_of_people; i++) {
			this->people[i] = people[i];
		}
	}
	this->checkIn = checkIn;
}

Guests::~Guests() {
	
}
//----------------------------------------------------------------

//setters ----------------------------------------------------------------------------
void Guests::setCheckIn(Date& d){
	checkIn = d;
}
void Guests::setCheckOut(Date& d){
	checkOut = d;
}
void Guests::setNo_of_people(int np){
	no_of_people = np;
}
void Guests::setRoomId(int ri){
	room_id = ri;
}
//-----------------------------------------------------------------

//other functions
std::string Guests::toString() {
	std::ostringstream value;
    value << "\nCheck in date: " << checkIn.toString() << " --- Check out date" << checkOut.toString() << " --- Room ID " << room_id << '\n';
	for (int i = 0; i < no_of_people; i++) {
		value << people[i].toString();
	}
	value << "\n";
	return value.str();
}

void Guests::printGuests(){
	std::cout << "Room ID: " << std::endl;
	std::cout << room_id << std::endl;
	std::cout << "Number of people: " << std::endl;
	std::cout << no_of_people << std::endl;

	std::cout << "Check In Date: " << std::endl;
	checkIn.printDate();

	std::cout << "Check Out Date: " << std::endl;
	checkOut.printDate();

	std::cout << "Room ID: " << std::endl;
	std::cout << room_id << std::endl;
	for(auto person : people){
		person.printInformation();
	}
}