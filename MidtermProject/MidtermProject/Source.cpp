#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Course.h"
#include "Semester.h"
#include "CourseSchedule.h"

using namespace std;

int main() {

	Time t1;
	//Course c1;
	Course c2("CS/IS 137", "C++", "MW", 4, *(new Date(3, 4, 2016)), *(new Date(18, 8, 2016)), *(new Time(18, 15)), *(new Time(20, 00)));
	Course c3("ENGL 101", "Freshmen English", "MWF", 3, *(new Date(3, 4, 2016)), *(new Date(18, 8, 2016)), *(new Time(10, 00)), *(new Time(11, 05)));
	Semester s1("Fall 2016", *(new Date(11, 11, 1111)), *(new Date(10,12, 2222)));

	CourseSchedule cs1("Thomas", s1, 10);

	cs1.addCourse(c2);
	cs1.addCourse(c3);
	cs1.print();

	cout << "-------------" << endl;

	cs1.removeCourse(2);
	cs1.print();

	/*cout << s1;

	cout << c2;*/



	system("pause");
	return 0;
}