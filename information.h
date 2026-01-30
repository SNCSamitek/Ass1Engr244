#pragma once

#include <string>
#include "information.h"
#include "date.h"

class Information {

private:
	char firstName[25];
	char lastName[25];
	Date dateOfBirth;

public:
	//constructors & desctructor
	Information();
	Information(Information const &obj);
	Information(char* firstName, char* lastName, Date dateOfBirth);
	~Information();

	//getters
	inline const char* getFirstName() const {return firstName;}
	inline const char* getLastName() const {return lastName;}
	inline Date getDateOfBirth()const {return dateOfBirth;}

	//setters
	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);

	//others
	std::string toString();
	void printInformation();
};