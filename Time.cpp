#include <iostream>
#include <iomanip>
using namespace std;

#include "Time.h"

//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do 
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute, int second)
{
 setTime(hour, minute, second);
}

/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute, int second)
{
 setHour(hour);
 setMinute(minute);
 setSecond(second);
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

//setSecond function is now set up to enable cascading
Time& Time::setSecond(int s)
{
  second = (s >= 0 && s < 24) ? s : 0;  //validates second, if valid set to s, else set to 0
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

//get Second
int Time::getSecond() const  //must be const since prototype is const
{
    return second;
}

/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
     cout << setfill('0') << setw(2) << hour << ":" 
          << setw(2) << minute << ":" << setw(2) << second << endl;
}

void Time::printStandard()const  //must be const since prototype is const
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" 
          << setfill ('0') << setw(2) << minute << ":" 
          << setw(2) << second << (hour < 12 ? "AM" : "PM" )<< endl;
}