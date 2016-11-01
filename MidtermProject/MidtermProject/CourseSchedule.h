//Team Sky.Net
//CSIS 137
//Midterm Project

#ifndef COURSE_SCHEDULE_H
#define COURSE_SCHEDULE_H

#include "Semester.h"
#include "Course.h"

class CourseSchedule {

	friend ostream& operator<<(ostream&, CourseSchedule&);

public:
	//constructor w/ 3 args: (studentName, semester, maxCourses)
	CourseSchedule(const string& studentName = "Student name not initialized",
		           const Semester& semester = Semester(), 
		           int MAXCOURSES = 6);

	//forbid copy constructor:
	CourseSchedule(const CourseSchedule&) = delete;

	//destructor:
	~CourseSchedule();

	//getters & setters:
	string getStudentName() const;
	CourseSchedule& setStudentName(const string&);
	Semester getSemester() const;
	int getNumCourses() const;
	string getCourseName(int) const;
	int getMAXCOURSES() const;
	bool addCourse(const Course&);
	bool removeCourse(int);

private:

	string studentName;
	Semester semester;
	Course* coursePtr;
	const int MAXCOURSES;
	int numCourses = 0;

	//utility functions:
	bool checkDates(const Course&);

};
#endif // !COURSE_SCHEDULE_H

