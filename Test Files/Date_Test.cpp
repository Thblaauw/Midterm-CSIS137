//Team Sky.Net
//CSIS 137
//Midterm Project

//Armen: Make sure to edit this to point to the directory where the Date.h file is located.
#include "F:\CS 137\Midterm-CSIS137-Date-Class-Armen-\Midterm-CSIS137-Date-Class-Armen-\MidtermProject\MidtermProject\Date.h"
#include <iostream>

using namespace std;

int main() {
	Date date(12, 10, 1996);

	cout << date << endl;

	cin >> date;

	cout << date << endl;

	date.setDate(10, 24, 2016);

	cout << date << endl;

	date.setMonth(6).setDay(15).setYear(2005);

	cout << date << endl;

	system("PAUSE");
	return 0;
}