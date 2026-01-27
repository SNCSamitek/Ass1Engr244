#include "date.h"

Date::Date() {
	year = 0;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d) {
	year = (y > 0) ? y : 0;
	month = (m >= 1 && m <= 12) ? m : 1;
	day = (d >= 1 && d <= 31) ? d : 1;
}

Date::Date(Date const &d) {
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

std::string Date::toString() {
	std::ostringstream value;
	value << year << ", " << month << ", " << day;
	return value.str();
}

void Date::setDay(int d) {
	day = (d >= 1 && d <= 31) ? d : 1;
}

void Date::setMonth(int m) {
	month = (m >= 1 && m <= 12) ? m : 1;
}

void Date::setYear(int y) {
	year = (y > 0) ? y : 0;
}