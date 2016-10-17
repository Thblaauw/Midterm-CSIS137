#ifndef SEMESTER_CPP
#define SEMESTER_CPP

#include "Semester.h"
#include <string>

Semester::Semester(std::string n, //name
	Date& startD, //startDate
	Date& endD) //endDate
{
	this->setName(n);
	this->setStartDate(startD);
	this->setEndDate(endD);
}

Semester::~Semester() {
	delete this->name;
	delete  this->startDate;
	delete this->endDate;
}

//-------------------------------------------------------------------------------------
//------------------------------------GETTERS AND SETTERS------------------------------
//-------------------------------------------------------------------------------------
std::string Semester::getName() {
	return *name;
}
Semester& Semester::setName(std::string& n) {
	if (name != nullptr) {
		std::string *deletedString = name;
		delete deletedString;
		name = nullptr;
	}
	this->name = new std::string(n);

	return *this;
}

Date Semester::getStartDate() {
	return *(startDate);
}
Semester& Semester::setStartDate(Date& d) {
	if (name != nullptr) {
		Date *deletedDate = startDate;
		delete deletedDate;
		startDate = nullptr;
	}
	this->startDate = new Date(d);
	return *this;
}

Date Semester::getEndDate() {
	return *(endDate);
}
Semester& Semester::setEndDate(Date& d) {
	if (name != nullptr) {
		Date *deletedDate = endDate;
		delete deletedDate;
		endDate = nullptr;
	}
	this->endDate = new Date(d);
	return *this;
}
//------------------------------------------------------------------------------------
//OPERATORS

ostream& operator<<(ostream& out, Semester& sem) {
	out << sem.getName() << "  (" << sem.getStartDate() << "-" << sem.getEndDate() << ")";

	return out;
}
istream& operator>> (istream& in, Semester& sem) {
	//cin.ignore(80, '\n');
	std::cout << "Enter the Semester Name:";
	std::string input;
	getline(cin, input);
	sem.setName(input);
	std::cout << std::endl;

	//cin.ignore(80, '\n');
	std::cout << "Enter the starting date:";
	std::cin >> *(sem.startDate);
	std::cout << std::endl;

	cin.ignore(80, '\n');
	std::cout << "Enter the ending date:";
	std::cin >> *(sem.endDate);

	return in;
}
#endif