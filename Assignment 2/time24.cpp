/*File: time24.cpp
  the class time24 represents time on 24 hour clock
  
  times are written to a stream in the form hour:minute
  
  when two times are added the minutes are added and if the sum is 60 or
  more then 60 is subtracted from the sum but the the hour is increased by
  1. If the hour is 24 or more then 24 is subtracted from the hour.
  
  Programmer:  Erin Aucoin
  Student ID:  B00631829
  Date:        September 22, 2017
*/

#include <iostream>
#include <fstream>
using namespace std;

class time24 {
private:
	int hour_; 					// hour between 0 and 23
	int minute_; 				// minute between 0 and 59
	
public:
	int hour(void) const; 		// return hour_
	int minute(void) const; 	// return minute_
	void hour(int h); 			// hour_ = h
	void minute(int m); 		// minute_ = m
};
void write(ostream &out, const time24 &x); 		// prints hour:minute
time24 add(const time24 &x, const time24 &y); 	// add x and y

int main(void) 					// test the class
{
	time24 x, y, z;
	
	x.hour(18);
	x.minute(34);
	y.hour(10);
	y.minute(56);
	
	cout << "The time x is: ";
	write(cout, x);
	
	cout << "\nThe time y is: ";
	write(cout, y);
	
	// try adding
	z = add(x, y);
	
	cout << "\nThe sum of ";
	write(cout, x);
	cout << " and ";
	write(cout, y);
	cout << " is ";
	write(cout, z);
	cout << endl;
	
	return 0;
}

int time24::hour() const
{
	return hour_;
}

int time24::minute() const
{
	return minute_;
}

void time24::hour(int h)
{
	hour_ = h;
}

void time24::minute(int m)
{
	minute_ = m;
}

void write(ostream &out, const time24 &x)
{
	out << x.hour() << ":" << x.minute() / 10 << x.minute() % 10;
}

time24 add(const time24 &x, const time24 &y)
{
	int hr_sum, min_sum;
	time24 z;
	
	hr_sum = x.hour() + y.hour();
	if(hr_sum >= 24) 
		hr_sum = hr_sum - 24;
	
	min_sum = x.minute() + y.minute();
	if(min_sum >=60)
	{
		min_sum = min_sum - 60;
		hr_sum++;
	}
	
	z.hour(hr_sum);
	z.minute(min_sum);
	
	return z;
}

