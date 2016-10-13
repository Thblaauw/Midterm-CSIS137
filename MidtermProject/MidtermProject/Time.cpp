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
  minute = (m >= 0 && m < 60) ? m : 0;  //validates minute, if valid set to m, else set to 0
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
          << setw(2) << (hour < 12 ? "AM" : "PM" )<< endl;
}

double Time::operator-(const Time& time)
{
	//convert t1 and t2 to minutes:
	int t1 = (this->getHour() * 60) + this->getMinute();
	int t2 = (time.getHour() * 60) + time.getMinute();

	//if t1 is greater than noon & larger than t2 (i.e. 4pm minus 2am)...
	if ((t1 > 720) && (t1 > t2)) {
		t1 = 1440 - t1;
		double diff = double(t1 + t2) / 60;
		return diff;
	}


	else {
		double diff = double(t1 - t2) / 60;
		//if the result is negative (i.e. 12am - 12pm) -> (0 - 12) = -12
		if (diff < 0) {
			diff *= -1;
		}

		return diff;
	}
}

ostream& operator<<(ostream& output, const Time& time)
{
	output << ((time.hour == 0 || time.hour == 12) ? 12 : time.hour % 12) << ":"
		<< setfill('0') << setw(2) << time.minute << ":"
		<< setw(2) << (time.hour < 12 ? "AM" : "PM") << endl;
	return output;
}

istream& operator >> (istream& in, Time& t) {
	string input;
	getline(in, input);
	int index = 4; //hold index of AM/PM (will be 4 units away from colon index)

	//loop through the string...
	for (int i = 1; i < input.size(); i++) {
		//to find the colon...
		if (input[i] == ':') {
			index += i; //store index for AM/PM
			//the hour is the substring before the colon...
			t.hour = stoi(input.substr(0, i), nullptr, 10);
			//the minute is the substring after the colon...
			t.minute = stoi(input.substr(i + 1, i + 2), nullptr, 10);
		}
	}

	//adjust for universal hours if user entered PM/pm
	if ((input[index] == 'P') || (input[index] == 'p')) {
		t.hour += 12;
	}
	//checks if user entered 12:xx AM, and adjusts to universal
	else if (t.hour == 12) {
		t.hour = 0;
	}
	//if user entered hour out of range, default to noon
	if ((t.hour < 0) || (t.hour > 23)) {
		t.hour = 12;
	}
	
	//if user entered minute out of range, default to zero
	if ((t.minute < 0) || (t.minute > 59)) {
		t.minute = 0;
	}

	return in;
}
