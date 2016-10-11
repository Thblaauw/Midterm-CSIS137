#ifndef COURSE_CPP
#define COURSE_CPP

#include "Course.h"

Course::Course(std::string number,	//courseNumber
	std::string name , //courseName
	std::string days, //meetingDays
	int unit, //unitCount
	Date startD, //startDate
	Date endD, //endDate
	Time startT, //startTime
	Time endT)//endTIme
{
	this->setCourseNumber(number);
	this->setCourseName(name);
	this->setMeetingDays(days);
	this->setUnitCount(unit);
	this->setStartDate(startD);
	this->setEndDate(endD);
	this->setStartTime(startT);
	this->setEndTime(endT);
}

Course::~Course() {

	std::cout << "A course has been deleted!" << std::endl;

	delete courseNumber;
	delete courseName;
	delete meetingDays;
	delete startDate;
	delete endDate;
	delete startTime;
	delete endTime;
}

double Course::calcDailyDuration() {
	return *endTime - *startTime;
}

//----------------------------------------------------------------------------------------------------
//------------------------------------------------GETTERS AND SETTERS---------------------------------
//----------------------------------------------------------------------------------------------------

//------------------------------------------------COURSE NUMBER-----------------------------------
std::string& Course::getCourseNumber() const{
	return *courseName;
}
Course& Course::setCourseNumber(std::string& num) {
	*courseNumber = num;
	return *this;
}
//------------------------------------------------COURSE NAME-------------------------------------
std::string& Course::getCourseName()const {
	return *courseName;
}
Course& Course::setCourseName(std::string& name) {
	*courseName = name;
	return *this;
}
//-----------------------------------------------MEETING DAYS--------------------------------------
std::string& Course::getMeetingDays()const {
	return *meetingDays;
}
Course& Course::setMeetingDays(std::string& days) {
	*meetingDays = days;
	return *this;
}
//-----------------------------------------------UNIT COUNT----------------------------------------
int Course::getUnitCount()const {
	return this->unitCount;
}
Course& Course::setUnitCount(int unit) {
	this->unitCount = unit;
	return *this;
}
//------------------------------------------------START DATE---------------------------------------
Date& Course::getStartDate()const {
	return *startDate;
}
Course& Course::setStartDate(Date& d) {
	//this->startDate->setDate(d.getMonth(), d.getDay(), d.getYear());
	return *this;
}
//------------------------------------------------END DATE------------------------------------------
Date& Course::getEndDate()const {
	return *endDate;
}
Course& Course::setEndDate(Date& d) {
	//this->endDate->setDate(d.getMonth(), d.getDay(), d.getYear());
	return *this;
}
//------------------------------------------------START TIME----------------------------------------
Time& Course::getStartTime()const {
	return *startTime;
}
Course& Course::setStartTime(Time& t) {
	this->startTime->setTime(t.getHour(), t.getMinute());
	return *this;
}
//-------------------------------------------------END TIME---------------------------------------------
Time& Course::getEndTime()const {
	return *endTime;
}
Course& Course::setEndTime(Time& t) {
	this->endTime->setTime(t.getHour(), t.getMinute());
	return *this;
}

#endif // !COURSE_CPP