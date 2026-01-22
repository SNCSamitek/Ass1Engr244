#pragma once

#include <string>
#include "information.h"
#include "date.h"

class Information {

private:
	char* firstName;
	char* lastName;
	Date dateOfBirth;

public:
	Information();
	Information(Information &obj);
	Information(char* firstName, char* lastName, Date dateOfBirth);
	~Information();

	std::string toString();
};