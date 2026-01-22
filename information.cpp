#include "information.h"
#include <iostream>
#include <sstream>

Information::Information() {
	this->firstName = "";
	this->lastName = "";
	this->dateOfBirth = Date();
}

Information::Information(Information const &obj) {
	this->firstName = obj.firstName;
	this->lastName = obj.lastName;
	this->dateOfBirth= obj.dateOfBirth;
}

Information::Information(char* firstName, char* lastName, Date dateOfBirth) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->dateOfBirth = dateOfBirth;
}

Information::~Information() {
	delete firstName;
	delete lastName;
}

std::string Information::toString() {
	std::ostringstream value;
    value << "Guest: " << firstName << " " << lastName << ", born on " << dateOfBirth.toString() << "\n";
	return value.str();
}
