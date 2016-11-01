//Team Sky.Net
//CSIS 137
//Midterm Project

#include "Semester.h"
#include <string>

Semester::Semester(const string& name, const Date& startDate, 
	               const Date& endDate)
{
	this->name = name;
	this->startDate = startDate;
	this->endDate = endDate;
}

string Semester::getName() const
{
	return name;
}

Semester& Semester::setName(const string& name)
{
	this->name = name;
	return *this;
}

Date Semester::getStartDate() const
{
	return startDate;
}

Semester & Semester::setStartDate(const Date& startDate)
{
	this->startDate = startDate;
	return *this;
}

Date Semester::getEndDate() const
{
	return endDate;
}

Semester& Semester::setEndDate(const Date& endDate)
{
	this->endDate = endDate;
	return *this;
}

ostream& operator<<(ostream& out, const Semester& s)
{
	out << s.getName() << "  (" << s.getStartDate() << " - " << s.getEndDate() << ")";
	return out;
}

istream& operator>>(istream& in, Semester& s)
{
	string input;
	cout << "Enter the Semester Name: " << endl;
	getline(in, input);
	s.name = input;

	cout << endl << "Enter the starting date: " << endl;
	in >> s.startDate;

	cout << endl << "Enter the ending date: " << endl;
	in >> s.endDate;

	return in;
}
