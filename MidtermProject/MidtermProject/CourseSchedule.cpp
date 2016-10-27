#ifndef COURSESCHEDULE_CPP
#define COURSESCHEDULE_CPP
#include "CourseSchedule.h"
#include "Course.h"
CourseSchedule::CourseSchedule(std::string name,
	Semester& semester,
	int maxCourses) 
{
	this->setStudentName(name);
	sem = new Semester(semester);
	this->maxCourses = maxCourses;
	this->numCourses = 0;
	const int MAXCOURSES = maxCourses;
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

bool CourseSchedule::addCourse(Course& c) {
	if (this->numCourses < this->maxCourses) {
		this->courses[numCourses] = c;
		numCourses++;
		return true;
	}
	return false;
}
bool CourseSchedule::removeCourse(int index) {
	if (index <= this->numCourses) {

		if (index == this->maxCourses - 1) {
			this->courses[index] = *new Course();
			this->numCourses--;
		}
		for (int i = 0; i < this->maxCourses - 1; i++) {
			if (i >= index) {
				this->courses[i] = this->courses[i + 1];
			}
		}
		this->numCourses--;
		return true;
	}
	return false;
}

void CourseSchedule::print() {

}
#endif // !COURSESCHEDULE_CPP