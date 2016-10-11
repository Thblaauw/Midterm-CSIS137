#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Course.h"

using namespace std;

int main() {

	Time t1;
	//Course c1;
	Course c2("CS/IS 137", "C++", "MW", 4, *(new Date(3, 4, 2016)), *(new Date(18, 8, 2016)), *(new Time(18, 15)), *(new Time(20, 00)));

	cout << c2 << endl;

	system("pause");
	return 0;
}