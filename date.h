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
	Date(Date const &d);

	inline int getYear() const {return year;};
	inline int getMonth() const {return month;};
	inline int getDay() const {return day;};

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	void printDate();
	std::string toString();
};