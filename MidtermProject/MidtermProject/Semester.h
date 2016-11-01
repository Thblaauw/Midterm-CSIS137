//Team Sky.Net
//CSIS 137
//Midterm Project

#ifndef SEMESTER_H
#define SEMESTER_H

#include "Date.h"

class Semester {
	friend ostream& operator<<(ostream&, const Semester&);
	friend istream& operator>>(istream&, Semester&);

public:
	//Constructor w/ 3 args:
	Semester(const string& name = "Semester name not defined", 
		     const Date& startDate = Date(), 
		     const Date& endDate = Date());

	//get & set functions:
	string getName() const;
	Semester& setName(const string&);
	Date getStartDate() const;
	Semester& setStartDate(const Date&);
	Date getEndDate() const;
	Semester& setEndDate(const Date&);

private:
	string name;
	Date startDate;
	Date endDate;
};



#endif // !SEMESTER_H
