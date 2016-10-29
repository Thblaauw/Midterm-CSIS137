//Team Sky.Net
//CSIS 137
//Midterm Project

#ifndef COURSE_H
#define COURSE_H

using namespace std;

#include "Time.h"
#include "Date.h"
#include <iostream>
#include <string>

class Course {

	friend ostream& operator<<(ostream&, const Course&);

public:

	//constructor with 8 args:
	Course(string courseNumber = "Course Number Undefined",
		string courseName = "Course Name Undefined",
		string meetingDays = "Meeting Days Undefined",
		int courseUnits = 0,
		Date startDate = Date(),
		Date endDate = Date(),
		Time startTime = Time(),
		Time endTime = Time());

	//destructor:
	~Course();

	//getters & setters:
	string getCourseNumber() const;
	Course& setCourseNumber(string&);
	string getCourseName() const;
	Course& setCourseName(string&);
	string getMeetingDays() const;
	Course& setMeetingDays(string&);
	int getCourseUnits() const;
	Course& setCourseUnits(int);
	Date getStartDate() const;
	Course& setStartDate(Date&);
	Date getEndDate() const;
	Course& setEndDate(Date&);
	Time getStartTime() const;
	Course& setStartTime(Time&);
	Time getEndTime() const;
	Course& setEndTime(Time&);

	//utility functions:
	double calcDailyDuration() const;
	
private:

	string courseNumber;
	string courseName;
	string meetingDays;
	int courseUnits;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
};

#endif // !COURSE_H

