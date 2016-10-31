#ifndef COURSESCHEDULE_CPP
#define COURSESCHEDULE_CPP
#include "CourseSchedule.h"
#include "Course.h"
CourseSchedule::CourseSchedule(std::string name,
	Semester& semester,
	int maxCourses) 
{
	this->setStudentName(name);
	sem = semester;
	this->maxCourses = maxCourses;
	this->numCourses = 0;
	const int MAXCOURSES = maxCourses;
	this->courses = new Course[maxCourses];
}
CourseSchedule::~CourseSchedule() {
	delete[] courses;
	//delete studentName;
}

CourseSchedule& CourseSchedule::setStudentName(std::string n) {
	this->studentName = n;
	return *this;
}
std::string CourseSchedule::getStudentName() {
	return studentName;
}

Semester& CourseSchedule::getSemester() {
	return sem;
}

int CourseSchedule::getMaxCourses() {
	return maxCourses;
}

int CourseSchedule::getNumCourses() {
	return numCourses;
}

bool CourseSchedule::addCourse(Course& c) {
	if (this->numCourses < this->maxCourses && checkDates(this->sem, c.getStartDate(), c.getEndDate() ) ) {
		this->courses[numCourses] = c;
		numCourses++;
		return true;
	}
	return false;
}
bool CourseSchedule::removeCourse(int index) {
	index--;
	if (index > numCourses - 1)
		return false;

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

std::ostream& operator<<(std::ostream& out, CourseSchedule& cs) {

	out << "CLASS SCHEDULE" << std::endl 
		<< "-----------------------------------------------------------" << std::endl
		<< "Name: " << cs.studentName << std::endl
		<< "Semester: " << cs.sem << std::endl
		<< "Number of Classes: " << cs.numCourses << std::endl
		<< "-----------------------------------------------------------" << std::endl;
	for (int i = 0; i < cs.numCourses; i++) {
		out << cs.courses[i] << endl;
	}

	return out;
}

bool CourseSchedule::checkDates(Semester& sem, Date& start, Date& end) {
	if (sem.getStartDate() < start && sem.getEndDate() > end)
		return true;

	return false;
}
#endif // !COURSESCHEDULE_CPP