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
	Course(const string& courseNumber = "Course Number Undefined",
		const string& courseName = "Course Name Undefined",
		const string& meetingDays = "Meeting Days Undefined",
		int courseUnits = 0,
		const Date& startDate = Date(),
		const Date& endDate = Date(),
		const Time& startTime = Time(),
		const Time& endTime = Time());

	//destructor:
	~Course();

	//getters & setters:
	string getCourseNumber() const;
	Course& setCourseNumber(const string&);
	string getCourseName() const;
	Course& setCourseName(const string&);
	string getMeetingDays() const;
	Course& setMeetingDays(const string&);
	int getCourseUnits() const;
	Course& setCourseUnits(int);
	Date getStartDate() const;
	Course& setStartDate(const Date&);
	Date getEndDate() const;
	Course& setEndDate(const Date&);
	Time getStartTime() const;
	Course& setStartTime(const Time&);
	Time getEndTime() const;
	Course& setEndTime(const Time&);

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
