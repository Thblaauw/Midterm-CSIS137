//Team Sky.Net
//CSIS 137
//Midterm Project

#include <iostream>
#include <iomanip>
using namespace std;

#include "Date.h"

ostream& operator<<(ostream& output, const Date& date) { //Armen: can a friend be const?
	cout << date.month << '/' << date.day << '/' << date.year;
	return output;
}

istream& operator>>(istream& input, Date& date) {
	int posCount = 1, numCount = 0;

	while (isdigit(input.get())) {
		posCount++;
		numCount++;
	}

	//posCount++;

	while (posCount != 0) {
		input.unget();
		posCount--;
	}

	switch (numCount) {
	//Armen: for format M/DD/YYYY
	case 1: 
		input >> setw(1) >> date.month;
		break;
	//Armen: for format MM/DD/YYYY
	case 2:
		input >> setw(2) >> date.month;
		break;
	default:
		cout << "ERROR in switch 1" << endl;
		//Armen: Anything for default?
	}

	input.ignore();

	numCount = 0;
	posCount = 1;

	//Armen: can there be a friend utility class for this?

	while (isdigit(input.get())) {
		posCount++;
		numCount++;
	}

	while (posCount != 0) {
		input.unget();
		posCount--;
	}

	switch (numCount) {
		//Armen: for format (M)M/D/YYYY
	case 1:
		input >> setw(1) >> date.day;
		break;
		//Armen: for format (M)M/DD/YYYY
	case 2:
		input >> setw(2) >> date.day;
		break;
	default:
		cout << "ERROR in switch 2" << endl;
		//Armen: Anything for default?
	}

	input.ignore();
	input >> date.year; //Armen: Should the format only be YYYY? //Armen: Should we only take first 4? What if they enter a fifth digit for year?

	return input;
}

//constructor validates month and calls utility function to validate day
Date::Date(int month, int day, int year) {
	this->setDate(month, day, year);
} //Armen: should constructor be above friend functions?



void Date::setDate(int month, int day, int year) //Armen: Should we make this cascadable?
{
	 if(month > 0 && month <= 12)
	 {
		 this->setMonth(month);
	 }
 
	 else
	 {
		 this->setMonth(1);
		 cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
		 //Armen: should we fix this if this is bad design?
	 }
 
	 this->setYear(year);  //could also validate year
	 //Armen: do we have to?
	 this->setDay(day);  //to validate the day
 
	 cout << endl;
}


//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(testDay > 0 && testDay <= daysPerMonth[month])
    {
		return testDay;
    }
    
    //determine whether testDay is valid for a specific month
    if(month == 2 && testDay == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
    {
		return testDay;
    }
    
    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}

//Armen: Instructions state that comparisons are based on hour and minutes. Shouldn't it be month, day, and year?
//Armen: Operators below haven't been tested. 
bool Date::operator>(const Date& date) const {
	//Armen: Instructions say to compare by time. Think it's a typo.
	if (this->year > date.year) {
		return true;
	}

	else if (this->year == date.year) {
		if (this->month > date.month) {
			return true;
		}
	}

	else if (this->year == date.year){
		if (this->month == date.month) {
			if (this->day > date.month) {
				return true;
			}
		}
	}

	return false;
}

bool Date::operator<(const Date& date) const {
	//Armen: Instructions say to compare by time. Think it's a typo.
	return !(this->operator>(date));
}

bool Date::operator>=(const Date& date) const {
	//Armen: Instructions say to compare by time. Think it's a typo.
	if (this->year > date.year) {
		return true;
	}

	else if (this->year == date.year) {
		if (this->month > date.month) {
			return true;
		}
	}

	else if (this->year == date.year){
		if (this->month == date.month) {
			if (this->day > date.month) {
				return true;
			}
		}
	}

	else if (this->operator==(date)) {
		return true;
	}

	return false;
}

bool Date::operator<=(const Date& date) const {
	//Armen: Instructions say to compare by time. Think it's a typo.
	return !(this->operator>=(date));
}

bool Date::operator==(const Date& date) const {
	//Armen: Instructions say to compare by time. Think it's a typo.
	if (this->year == date.year){
		if (this->month == date.month) {
			if (this->day == date.month) {
				return true;
			}
		}
	}

	return false;
}

bool Date::operator!=(const Date& date) const {
	//Armen: Instructions say to compare by time. Think it's a typo.
	return !(this->operator==(date));
}

int Date::getMonth() const {
	return this->month;
}

int Date::getDay() const {
	return this->day;
}

int Date::getYear() const {
	return this->year;
}

Date& Date::setMonth(int month) {
	this->month = month;
	return *this;
}

Date& Date::setDay(int day) {
	this->day = this->checkDay(day);
	return *this;
}

Date& Date::setYear(int year) {
	this->year = year;
	return *this;
}

//DESTRUCTOR
Date::~Date()
{
	//Armen: is this even needed?
}