#ifndef COURSESCHEDULE_CPP
#define COURSESCHEDULE_CPP
#include "CourseSchedule.h"
CourseSchedule::CourseSchedule(std::string name,
	Semester& semester,
	int maxCourses) 
{
	this->setStudentName(name);
	sem = new Semester(semester);
	this->maxCourses = maxCourses;
	this->courses = 0;
	courses = new Course[this->maxCourses];
}
CourseSchedule::~CourseSchedule() {
	delete sem;
	delete[] courses;
	delete studentName;
}

CourseSchedule& CourseSchedule::setStudentName(std::string n) {
	this->studentName = new std::string(n);
	return *this;
}
std::string CourseSchedule::getStudentName() {
	return *studentName;
}

//CourseSchedule& CourseSchedule::setSemester(Semester&);
Semester& CourseSchedule::getSemester() {
	return *sem;
}

//CourseSchedule CourseSchedule::setCourse(int, Semester&);
//Course& CourseSchedule::getCourse(int);

int CourseSchedule::getMaxCourses() {
	return maxCourses;
}

int CourseSchedule::getNumCourses() {
	return numCourses;
}

bool CourseSchedule::addCourse(Course&) {
	return true;
}
bool CourseSchedule::removeCourse(int) {
	return true;
}
#endif // !COURSESCHEDULE_CPP