//Team Sky.Net
//CSIS 137
//Midterm Project

#include <iostream>
using namespace std;

#include "Date.h"
#include <string>

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
	setDate(mn, dy, yr);
}

void Date::setDate(int mn, int dy, int yr)
{
	if (mn > 0 && mn <= 12)
	{
		month = mn;
	}

	else
	{
		month = 1;
		cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
	}

	year = yr;  //could also validate year

	day = checkDay(dy);  //to validate the day

	cout << endl;
}

Date& Date::setMonth(int mn)
{
	if (mn > 0 && mn <= 12)
	{
		month = mn;
	}

	else
	{
		month = 1;
	}

	return *this;
}

Date& Date::setDay(int dy)
{
	day = checkDay(dy);
	return *this;
}

Date& Date::setYear(int yr)
{
	year = yr;
	return *this;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

bool Date::operator>(const Date& date) const
{
	if (this->year > date.year) {
		return true;
	}

	else if (this->year == date.year) {
		if (this->month > date.month) {
			return true;
		}
		else if (this->month == date.month) {
			if (this->day > date.day) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator<(const Date& date) const
{
	if (this->year < date.year) {
		return true;
	}

	else if (this->year == date.year) {
		if (this->month < date.month) {
			return true;
		}
		else if (this->month == date.month) {
			if (this->day < date.day) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator>=(const Date& date) const
{
	if (this->year > date.year) {
		return true;
	}

	else if (this->year == date.year) {
		if (this->month > date.month) {
			return true;
		}
		else if (this->month == date.month) {
			if (this->day >= date.day) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator<=(const Date& date) const
{
	if (this->year < date.year) {
		return true;
	}

	else if (this->year == date.year) {
		if (this->month < date.month) {
			return true;
		}
		else if (this->month == date.month) {
			if (this->day <= date.day) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date& date) const
{
	if (this->year == date.year) {
		if (this->month == date.month) {
			if (this->day == date.day) {
				return true;
			}
		}
	}

	return false;
}

bool Date::operator!=(const Date& date) const
{
	return !(this->operator==(date));
}

//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (testDay > 0 && testDay <= daysPerMonth[month])
	{
		return testDay;
	}

	//determine whether testDay is valid for a specific month
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
	{
		return testDay;
	}

	cout << "Invalid Day " << testDay << " was set to 1" << endl;
	return 1;  //keep data in valid state
}

ostream & operator<<(ostream& out, const Date& date)
{
	cout << date.month << '/' << date.day << '/' << date.year;
	return out;
}

istream & operator >> (istream& in, Date& date)
{
	string input;
	getline(in, input);
	int numSettersCalled = 0; //checks how many Date set functions have been called...
	int index = 0;

	//loop through the string...
	for (int i = 1; numSettersCalled < 3; i++) {
		if ((input[i] == '/') && (numSettersCalled == 0)) {
			date.setMonth(stoi(input.substr(index, i)));
			numSettersCalled++;
			index = (i + 1);
		}

		else if ((input[i] == '/') && (numSettersCalled == 1)) {
			date.setDay(stoi(input.substr(index, i - index)));
			numSettersCalled++;
			index = (i + 1);
			date.setYear(stoi(input.substr(index, 4)));
			numSettersCalled++;
		}
	}

	return in;
}
