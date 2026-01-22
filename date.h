#pragma once
#include <string>
#include <sstream>

class Date {

private:
	int year;
	int month; 
	int day;

public:
	Date();
	Date(int y, int m, int d);
	Date(Date &d);

	int getYear() const {return year;};
	int getMonth() const {return month;};
	int getDay() const {return day;};

	std::string toString();
};