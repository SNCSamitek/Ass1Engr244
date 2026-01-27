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
	Information();
	Information(Information const &obj);
	Information(char* firstName, char* lastName, Date dateOfBirth);
	~Information();

	std::string toString();
	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);
	void printInformation();
};