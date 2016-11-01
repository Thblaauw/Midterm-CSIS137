//Team Sky.Net
//CSIS 137
//Midterm Project

#include "CourseSchedule.h"

CourseSchedule::CourseSchedule(const string& studentName, 
	const Semester& semester, int MAX) : MAXCOURSES(MAX)
{
	this->studentName = studentName;
	this->semester = semester;
	coursePtr = new Course[MAXCOURSES];
}

CourseSchedule::~CourseSchedule()
{
	delete [] coursePtr;
}

string CourseSchedule::getStudentName() const
{
	return studentName;
}

CourseSchedule& CourseSchedule::setStudentName(const string& studentName)
{
	this->studentName = studentName;
	return *this;
}

Semester CourseSchedule::getSemester() const
{
	return semester;
}

int CourseSchedule::getNumCourses() const
{
	return numCourses;
}

string CourseSchedule::getCourseName(int index) const
{
	return coursePtr[index].getCourseName();
}

int CourseSchedule::getMAXCOURSES() const
{
	return MAXCOURSES;
}

bool CourseSchedule::addCourse(const Course& c)
{
	if (checkDates(c)) {
		if (numCourses < MAXCOURSES) {
			coursePtr[numCourses] = c;
			numCourses++;
			return true;
		}
	}

	return false;
}

bool CourseSchedule::removeCourse(int index)
{
	if (index < numCourses) {

		if (index == MAXCOURSES - 1) {
			coursePtr[index] = *new Course();
			numCourses--;
			return true;
		}

		else {
			for (int i = index; i < MAXCOURSES-1; i++) {
				coursePtr[index] = coursePtr[index + 1];
			}
			coursePtr[MAXCOURSES - 1] = *new Course();
			numCourses--;
			return true;
		}
	}

	return false;
}

bool CourseSchedule::checkDates(const Course& course)
{
	if ((semester.getStartDate() <= course.getStartDate()) &&
		(semester.getEndDate() >= course.getEndDate())) {
		return true;
	}

	return false;
}

ostream & operator<<(ostream& out, CourseSchedule& c)
{
	out << "CLASS SCHEDULE" << endl
		<< "-----------------------" << endl
		<< "Name: " << c.studentName << endl
		<< "Semester: " << c.semester << endl
		<< "Number of Classes: " << c.numCourses << endl
		<< "-----------------------------------------------------------" << endl;
	for (int i = 0; i < c.numCourses; i++) {
		cout << "[COURSE " << (i + 1) << "]" << endl;
		cout << c.coursePtr[i] << endl;
	}

	return out;
}
