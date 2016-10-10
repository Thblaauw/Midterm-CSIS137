#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do 
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute)
{
 setTime(hour, minute);
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute)
{
 setHour(hour);
 setMinute(minute);
 return *this; 
}

//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
  hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
  return *this;
}  

//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
  minute = (m >= 0 && m < 24) ? m : 0;  //validates minute, if valid set to m, else set to 0
  return *this;
} 

/*GET FUNCTIONS:  Do not modify private member data normally always const*/

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}

//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
     cout << setfill('0') << setw(2) << hour << ":" 
          << setw(2) << minute << endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" 
          << setfill ('0') << setw(2) << minute << ":" 
		  << (hour < 12 ? "AM" : "PM" )<< endl;
}

//FRIEND functions :

ostream& operator<<(ostream& out, const Time& t) {
	// cout function
	//this will print the standart hour

	out << ((t.getHour() == 0 || t.getHour() == 12) ? 12 : t.getHour() % 12) << ":"
		<< setfill('0') << setw(2) << t.getMinute() << ":"
		<< (t.getMinute() < 12 ? "AM" : "PM") << endl;

	return out;
}

istream& operator>> (istream& in, Time& t) {
	string input;
	cin.ignore(80, '\n');
	getline(cin, input);

	int hour = 0;
	int min = 0;
	for (int i = 1; i < input.size(); i++) {
		if (input[i] == ':') {
			hour = stoi(input.substr(0, i), nullptr, 10);
			min = stoi(input.substr(i+1, i+2), nullptr, 10);
			if (input.substr(i + 4, i + 5) == "PM" || input.substr(i + 4, i + 5) == "pm") {
				hour += 12;
			}
			break;
		}
	}

	t.setTime(hour, min);

	return in;
}

//operators
double Time::operator-(const Time& t2) const{
	//This is creating a new time and passing it.
	//I don't know if we are suposed to do that or just to change 
	// the Time that called this operator

	int min = this->getMinute() - t2.getMinute();
	int hour = this->getHour() - t2.getHour();

	int timeDifference = hour + (min / 60);//this will return whole hours and some decimal, which will represent the minutes
	
	return timeDifference;
}