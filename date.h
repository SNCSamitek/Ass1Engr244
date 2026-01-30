#pragma once
#include <string>
#include <sstream>

class Date {

private:
	int year;
	int month; 
	int day;

public:
	//constructors & destructors
	Date();
	Date(int y, int m, int d);
	Date(Date const &d);

	//getters
	inline int getYear() const {return year;};
	inline int getMonth() const {return month;};
	inline int getDay() const {return day;};

	//setters
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	//others
	void printDate() const;
	std::string toString();
};