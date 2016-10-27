#ifndef COURSE_H
#define COURSE_H

#include "Time.h"
#include "Date.h"
#include <string>
#include <iostream>

//TODO: implementations of operator<<

class Course {
	
	friend std::ostream& operator<<(std::ostream&, Course&);

private:

	std::string courseNumber;
	std::string courseName;
	std::string meetingDays;

	int unitCount;
	
	Date *startDate;
	Date *endDate;

	Time *startTime;
	Time *endTime;

public:
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
	Course(std::string number = "Course Number Undefined",//courseNumber
		std::string name = "Course Name Undefined", //courseName
		std::string days = "Meeting Days Udefined", //meetingDays
		int unit = 0, //unitCount
		Date startD = Date(), //startDate
		Date endD = Date(), //endDate
		Time startT = Time(), //startTime
		Time endT = Time());

	~Course();

	double calcDailyDuration();

	std::string getCourseNumber()const;
	Course& setCourseNumber(std::string&);

	std::string getCourseName()const;
	Course& setCourseName(std::string&);

	std::string getMeetingDays()const;
	Course& setMeetingDays(std::string&);

	int getUnitCount()const;
	Course& setUnitCount(int);

	Date getStartDate()const;
	Course& setStartDate(Date&);

	Date getEndDate()const;
	Course& setEndDate(Date&);

	Time getStartTime()const;
	Course& setStartTime(Time&);

	Time getEndTime()const;
	Course& setEndTime(Time&);

};

#endif
