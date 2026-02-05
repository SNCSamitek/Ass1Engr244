#include "information.h"
#include <iostream>
#include <sstream>
#include <cstring>


//constructors and destructors ------------------------------------------------------------
Information::Information() {
    firstName[0] = '\0';
    lastName[0] = '\0';
	this->dateOfBirth = Date();
}

Information::Information(Information const &obj) {
	setFirstName(obj.firstName);
	setLastName(obj.lastName);
	this->dateOfBirth= obj.dateOfBirth;
}

Information::Information(char* firstName, char* lastName, Date dateOfBirth) {
	setFirstName(firstName);
	setLastName(lastName);
	this->dateOfBirth = dateOfBirth;
}

Information::~Information() {
	
}
// --------------------------------------------------------------------------------------

//setters -----------------------------------------------------------------------------------
void Information::setFirstName(const char* firstName) {
    if (!firstName) {        
        this->firstName[0] = '\0';
        return;
    }

    size_t len = std::strlen(firstName);

    size_t i;
    for (i = 0; i < len && i < sizeof(this->firstName) - 1; i++) {
        this->firstName[i] = firstName[i];
    }

    this->firstName[i] = '\0';
}

void Information::setLastName(const char* lastName) {
	if (!lastName) {        
        this->lastName[0] = '\0';
        return;
    }

    size_t len = std::strlen(lastName);

    size_t i;
    for (i = 0; i < len && i < sizeof(this->lastName) - 1; i++) {
        this->lastName[i] = lastName[i];
    }
	
    this->lastName[i] = '\0';
}
//-------------------------------------------------------------------------------------

//other ----------------------------------------------------------------------------
// Prints the First Name, Last Name, and Date of Birth of the Person
void Information::printInformation(){
    std::cout << "First name: " << firstName;
    std::cout << std::endl;

    std::cout << "Last name: " << lastName;
    std::cout << std::endl << std::endl;

    std::cout << "Date Of Birth: " << std::endl;
    dateOfBirth.printDate();
}

// Returns a string of "Guest: {firstName} {lastName}, born on {dateOfBirth}\n"
std::string Information::toString() {
	std::ostringstream value;
    value << "Guest: " << firstName << " " << lastName << ", born on " << dateOfBirth.toString() << "\n";
	return value.str();
}
//----------------------------------------------------------------------------