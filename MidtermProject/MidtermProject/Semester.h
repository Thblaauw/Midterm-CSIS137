#ifndef SEMESTER_H
#define SEMESTER_H

#include <string>
#include "Date.h"
#include <iostream>

class Semester {

	friend ostream& operator<<(ostream&, Semester&);
	friend istream& operator>>(istream&, Semester&);

private:
	std::string *name;
	Date *startDate;
	Date *endDate;

public:
	Semester(std::string& = "Semester not defined", //name
		Date& = Date(), //startDate
		Date& = Date()); //endDate

	~Semester();

	std::string getName();
	Semester& setName(std::string&);

	Date getStartDate();
	Semester& setStartDate(Date&);

	Date getEndDate();
	Semester& setEndDate(Date&);
};
#endif // !SEMESTER_H