//Team Sky.Net
//CSIS 137
//Midterm Project

#include "CourseSchedule.h"

int main()
{
	string userString1;
	string userString2;
	string userString3;
	Date d1;
	Date d2;
	int userNum;
	char userInput = 0;
	Time t1;
	Time t2;

	cout << "Thanks for using Sky.net to schedule your semester!" << endl << endl
		<< "Please enter your name: " << endl;
	getline(cin, userString1);

	cout << endl << "Please enter the semester you are creating a schedule for: " << endl;
	getline(cin, userString2);

	cout << endl << "What is the starting date of this semester?" << endl
		<< "Enter in the format: MM/DD/YYYY" << endl;
	cin >> d1;

	cout << endl << "What is the ending date of this semester?" << endl
		<< "Enter in the format: MM/DD/YYYY" << endl;
	cin >> d2;

	cout << endl << "How many courses are you allowed to take this semester?" << endl;
	cin >> userNum;

	Semester sem(userString2, d1, d2);
	CourseSchedule cs(userString1, sem, userNum);

	do {
		cout << endl << "COURSE ENTRY MENU FOR: " << sem << endl
			<< "----------------------------------------------------------" << endl
			<< "1) Enter a new course" << endl
			<< "2) Remove a course" << endl
			<< "3) Print a Semester Schedule" << endl
			<< "Q) Quit the program" << endl;
		cin >> userInput;
		cin.ignore();

		if (userInput == '1') {
			if (cs.getNumCourses() < cs.getMAXCOURSES()) {
				cout << endl << "Enter in the course number: " << endl;

				getline(cin, userString1);

				cout << endl << "Enter the course name:	" << endl;
				getline(cin, userString2);

				cout << endl << "Enter the meeting days: (EX: MW, TTH)" << endl;
				getline(cin, userString3);

				cout << endl << "How many units is this course?" << endl;
				cin >> userNum;
				cin.ignore();

				cout << endl << "What time does the class start? (EX: 10:05 AM)" << endl;
				cin >> t1;

				cout << endl << "What time does the class end? (EX: 12:55 PM)" << endl;
				cin >> t2;

				cout << endl << "What is the starting date of this course? (EX: 1/12/2016)" << endl;
				cin >> d1;

				cout << endl << "What is the ending date of this course? (EX: 6/6/2016)" << endl;
				cin >> d2;

				Course c(userString1, userString2, userString3, userNum, d1, d2, t1, t2);

				if (cs.addCourse(c)) {
					cout << "[" << cs.getCourseName(cs.getNumCourses() - 1) << "] successfully added!" << endl;
				}
				else {
					cout << "Course not added!" << endl
						<< "Course dates do not fall within semester dates!" << endl;
				}
			}

			else {
				cout << endl << "Course schedule already full!" << endl
					<< "Please remove a course from your schedule before adding another!" << endl;
			}
		}

		else if (userInput == '2') {
			if (cs.getNumCourses() > 0) {
				for (int i = 0; i < cs.getNumCourses(); i++) {
					cout << "[COURSE " << i + 1 << "] = " << cs.getCourseName(i) << endl;
				}

				cout << "Which course would you like to delete?" << endl;
				cin >> userNum;
				if (userNum <= cs.getNumCourses()) {
					if (cs.removeCourse(userNum - 1)) {
						cout << "Course successfully removed!" << endl;
					}
					else {
						cout << "Error: Course not removed!" << endl;
					}
				}
			}

			else {
				cout << endl << "No courses have been added yet!" << endl << endl;
			}
			
		}

		else if (userInput == '3') {
			cout << endl << cs << endl;
		}

		else if ((userInput == 'q') || (userInput == 'Q')) {
			cout << endl << "Sky.net thanks you for using this program!" << endl << endl;
		}

		else {
			cout << endl << "Invalid input.  Try again!" << endl << endl;
		}

	} while ((userInput != 'q') && (userInput != 'Q'));

	system("PAUSE");
    return 0;
}
