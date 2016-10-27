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
	Semester s1;
	CourseSchedule cs1("Thomas", s1, 10);
	cin >> s1;

	cout << s1;

	cout << c2;

	system("pause");
	return 0;
}