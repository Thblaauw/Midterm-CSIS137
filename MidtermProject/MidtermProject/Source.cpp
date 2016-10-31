#include <iostream>
//#include "Date.h"
//#include "Time.h"
#include "Course.h"
//#include "Semester.h"
#include "CourseSchedule.h"

using namespace std;

int main() {

	//Time t1;
	////Course c1;
	//Course c2("CS/IS 137", "C++", "MW", 4, *(new Date(3, 4, 2016)), *(new Date(8, 18, 2016)), *(new Time(18, 15)), *(new Time(20, 00)));
	//Course c3("ENGL 101", "Freshmen English", "MWF", 3, *(new Date(3, 4, 2016)), *(new Date(8, 8, 2016)), *(new Time(10, 00)), *(new Time(11, 05)));
	//Course c4("CS/IS 137", "C++", "TTH", 4, *(new Date(1, 1, 1000)), *(new Date(1, 1, 1000)), *(new Time(18, 15)), *(new Time(20, 00)));
	//Semester s1("Fall 2016", *(new Date(1, 2, 2016)), *(new Date(10,12, 2016)));
	//CourseSchedule cs1("Thomas", s1, 10);
	//cs1.addCourse(c2);
	//cs1.addCourse(c3);
	//cs1.addCourse(c4);
	//cs1.print();
	//cout << "-------------" << endl;
	//cs1.removeCourse(4);
	//cs1.print();
	string userName;
	Semester sem;
	int maxCourses;

	char menuEntry;

	cout << "Please enter your name:";
	getline(cin, userName);
	cin >> sem;
	cout << "Please enter the maximum number of courses:";
	cin >> maxCourses;
	
	CourseSchedule schedule(userName, sem, maxCourses);

	do {
		system("cls");
		cout << "COURSE ENTRY MENU FOR: " << sem << endl
			<< "------------------------------------------------------------------------" << endl
			<< "1) Enter a new course" << endl
			<< "2) Remove a course" << endl
			<< "3) Print a Semester Schedule" << endl
			<< "q) Quit the program" << endl;

		cin >> menuEntry;

		switch (menuEntry) {
		case '1':
			break;

		case '2':
			int courseIndex;
			system("cls");
			cout << "Enter the number of the course you want to delete: ";
			cin.ignore(80, '\n');
			cin >> courseIndex;
			schedule.removeCourse(courseIndex);
			break;

		case '3':
			system("cls");
			cout << schedule;
			system("pause");
			break;

		case 'q':
			break;
		case 'Q':
			break;
		default:
			cout << "Invalid Option" << endl;
			system("pause");
		}
	} while (menuEntry != 'q');

	return 0;
}