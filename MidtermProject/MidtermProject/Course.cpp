#ifndef COURSE_CPP
#define COURSE_CPP

#include "Course.h"
#include <iomanip>
/** @author Thomas Blaauw Barbosa

	@param number
	String with the course Number

	@param name
	String with the course Name

	@param days
	String with the meeting days

	@param unit
	Integer that represents the unit count

	@param startD
	Date datatype with the Starting Date

	@param endD
	Date datatype with the Ending Date

	@param startT
	Time datatype with the Stating Time

	@param endT
	Time datatype with the Ending Time
*/
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
	/*std::string tempMeetingDays = *(new std::string(*meetingDays));
	int dayCount = 0;
	for (int i = 0; i < tempMeetingDays.size(); i++){
		if (tempMeetingDays[i] == 'M' || tempMeetingDays[i] == 'T' || tempMeetingDays[i] == 'W' || tempMeetingDays[i] == 'F' || tempMeetingDays[i] == 'S') {
			dayCount++;
		}
	}*/
	return ((*endTime - *startTime));
}
std::ostream& operator<<(std::ostream& out, Course& c) {
	out  << "Course Info:" << "\t" << c.getCourseNumber() << " -- " << c.getCourseName() << std::endl
		 << "# of units:" << "\t" << (double)c.getUnitCount() << std::endl
		//<< "Course Dates:" << "\t" << c.getStartDate() << " - " << c.getEndDate() << std::endl
		<< "Meeting Days:" << "\t" << c.getMeetingDays() << std::endl
		<< "Meeting Time:" << "\t" << c.getStartTime()<< "-"  << c.getEndTime() << std::endl
		<< "Daily Duration:" << "\t" << std::setprecision(3) << c.calcDailyDuration() << std::endl;

	return out;
}
//----------------------------------------------------------------------------------------------------
//------------------------------------------------GETTERS AND SETTERS---------------------------------
//----------------------------------------------------------------------------------------------------

//------------------------------------------------COURSE NUMBER-----------------------------------
std::string& Course::getCourseNumber() const{
	return *courseNumber;
}
Course& Course::setCourseNumber(std::string& num) {
	if (courseNumber != nullptr) {
		std::string* deletedString = courseNumber;
		delete deletedString;
		courseNumber = nullptr;
	}
	courseNumber = new std::string(num);
	return *this;
}
//------------------------------------------------COURSE NAME-------------------------------------
std::string& Course::getCourseName()const {
	return *courseName;
}
Course& Course::setCourseName(std::string& name) {
	if (courseName != nullptr) {
		std::string* deletedString = courseName;
		delete deletedString;
		courseName = nullptr;
	}
	courseName = new std::string(name);
	return *this;
}
//-----------------------------------------------MEETING DAYS--------------------------------------
std::string& Course::getMeetingDays()const {
	return *meetingDays;
}
Course& Course::setMeetingDays(std::string& days) {
	if (meetingDays != nullptr) {
		std::string* deletedString = meetingDays;
		delete deletedString;
		meetingDays = nullptr;
	}
	meetingDays = new std::string(days);
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
	startTime = new Time(t.getHour(), t.getMinute());
	return *this;
}
//-------------------------------------------------END TIME---------------------------------------------
Time& Course::getEndTime()const {
	return *endTime;
}
Course& Course::setEndTime(Time& t) {
	endTime = new Time(t.getHour(), t.getMinute());
	return *this;
}

#endif // !COURSE_CPP