#ifndef COURSE_CPP
#define COURSE_CPP

#include "Course.h"
#include <iomanip>

Course::Course(std::string number ,//courseNumber
	std::string name , //courseName
	std::string days, //meetingDays
	int unit, //unitCount
	Date startD, //startDate
	Date endD, //endDate
	Time startT, //startTime
	Time endT) //endTIme
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

	/*delete courseNumber;
	delete courseName;
	delete meetingDays;
	delete startDate;
	delete endDate;
	delete startTime;
	delete endTime;

	*/
}

double Course::calcDailyDuration() {
	std::string tempMeetingDays = this->meetingDays;
	int dayCount = 0;
	for (int i = 0; i < tempMeetingDays.size(); i++){
		if (tempMeetingDays[i] == 'M' || tempMeetingDays[i] == 'T' || tempMeetingDays[i] == 'W' || tempMeetingDays[i] == 'F' || tempMeetingDays[i] == 'S') {
			dayCount++;
		}
	}
	return ((endTime - startTime));
}
std::ostream& operator<<(std::ostream& out, Course& c) {
	out << "Course Info:" << "\t" << c.getCourseNumber() << " -- " << c.getCourseName() << std::endl
		<< "# of units:" << "\t" << (double)c.getUnitCount() << std::endl
		<< "Course Dates:" << "\t" << c.getStartDate() << " - " << c.getEndDate() << std::endl
		<< "Meeting Days:" << "\t" << c.getMeetingDays() << std::endl
		<< "Meeting Time:" << "\t" << c.getStartTime()<< " -- "  << c.getEndTime() << std::endl
		<< "Daily Duration:" << "\t" << std::setprecision(3) << c.calcDailyDuration() << std::endl;

	return out;
}
//----------------------------------------------------------------------------------------------------
//------------------------------------------------GETTERS AND SETTERS---------------------------------
//----------------------------------------------------------------------------------------------------

//------------------------------------------------COURSE NUMBER-----------------------------------
std::string Course::getCourseNumber() const{
	return courseNumber;
}
Course& Course::setCourseNumber(std::string& num) {
	courseNumber = num;
	return *this;
}
//------------------------------------------------COURSE NAME-------------------------------------
std::string Course::getCourseName()const {
	return courseName;
}
Course& Course::setCourseName(std::string& name) {
	this->courseName = name;
	return *this;
}
//-----------------------------------------------MEETING DAYS--------------------------------------
std::string Course::getMeetingDays()const {
	return meetingDays;
}
Course& Course::setMeetingDays(std::string& days) {
	this->meetingDays = days;
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
Date Course::getStartDate()const {
	return startDate;
}
Course& Course::setStartDate(Date& d) {
	this->startDate = d;
	return *this;
}
//------------------------------------------------END DATE------------------------------------------
Date Course::getEndDate()const {
	return endDate;
}
Course& Course::setEndDate(Date& d) {
	this->endDate = d;
	return *this;
}
//------------------------------------------------START TIME----------------------------------------
Time Course::getStartTime()const {
	return startTime;
}
Course& Course::setStartTime(Time& t) {
	startTime = t;
	return *this;
}
//-------------------------------------------------END TIME---------------------------------------------
Time Course::getEndTime()const {
	return endTime;
}
Course& Course::setEndTime(Time& t) {
	endTime = t;
	return *this;
}

#endif // !COURSE_CPP