//Team Sky.Net
//CSIS 137
//Midterm Project

#include "Course.h"
#include <iomanip>

using namespace std;

Course::Course(const string& courseNumber, const string& courseName, 
	const string& meetingDays, int courseUnits, const Date& startDate, 
	const Date& endDate, const Time& startTime, const Time& endTime)
{
	this->courseNumber = courseNumber;
	this->courseName = courseName;
	this->meetingDays = meetingDays;
	this->courseUnits = courseUnits;
	this->startDate = startDate;
	this->endDate = endDate;
	this->startTime = startTime;
	this->endTime = endTime;
}

Course::~Course()
{
	cout << "Course: " << courseNumber << " - " << courseName << " has been deleted!" << endl;
}

string Course::getCourseNumber() const
{
	return courseNumber;
}

Course& Course::setCourseNumber(const string& courseNumber)
{
	this->courseNumber = courseNumber;
	return *this;
}

string Course::getCourseName() const
{
	return courseName;
}

Course& Course::setCourseName(const string& courseName)
{
	this->courseName = courseName;
	return *this;
}

string Course::getMeetingDays() const
{
	return meetingDays;
}

Course& Course::setMeetingDays(const string& meetingDays)
{
	this->meetingDays = meetingDays;
	return *this;
}

int Course::getCourseUnits() const
{
	return courseUnits;
}

Course& Course::setCourseUnits(int courseUnits)
{
	this->courseUnits = courseUnits;
	return *this;
}

Date Course::getStartDate() const
{
	return startDate;
}

Course& Course::setStartDate(const Date& startDate)
{
	this->startDate = startDate;
	return *this;
}

Date Course::getEndDate() const
{
	return endDate;
}

Course& Course::setEndDate(const Date& endDate)
{
	this->endDate = endDate;
	return *this;
}

Time Course::getStartTime() const
{
	return startTime;
}

Course& Course::setStartTime(const Time& startTime)
{
	this->startTime = startTime;
	return *this;
}

Time Course::getEndTime() const
{
	return endTime;
}

Course& Course::setEndTime(const Time& endTime)
{
	this->endTime = endTime;
	return *this;
}

double Course::calcDailyDuration() const
{
	return getEndTime() - getStartTime();
}


ostream& operator<<(ostream& out, const Course& c)
{
	out << "Course Info:" << "\t" << c.getCourseNumber() << " -- " << c.getCourseName() << endl
		<< "# of units:" << "\t" << fixed << setprecision(2) << (double)c.getCourseUnits() << endl
		<< "Course Dates:" << "\t" << c.getStartDate() << " - " << c.getEndDate() << endl
		<< "Meeting Days:" << "\t" << c.getMeetingDays() << endl
		<< "Meeting Time:" << "\t" << c.getStartTime() << " - " << c.getEndTime() << endl
		<< "Daily Duration:" << "\t" << c.calcDailyDuration() << " hours" << endl;

	return out;
}
