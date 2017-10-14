/*File: time24methods.cpp
  the class time24 represents time on 24 hour clock
  
  times are written to a stream in the form hour:minute
  
  when a time is added to the current time the minutes are added and if
  the sum is 60 or more then 60 is subtracted from the sum but the the
  hour is increased by 1. If the hour is 24 or more then 24 is subtrated
  from the hour.

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
	time24(int h = 0 , int m = 0); 		// constructor with default args
	void write(ostream &out); 			// prints hour:minute to out
	time24 add(const time24 &y) const; 	// add y to current time
};

int main(void) 					// test the class
{
	time24 x(18,34), y(10,56), z;
	
	cout << "The time x is: ";
	x.write(cout);
	
	cout << "\nThe time y is: ";
	y.write(cout);
	
	// try conversion
	z = 12;
	cout << "\nThe time z is: ";
	z.write(cout);
	
	// try adding
	z = x.add(y);
	
	cout << "\nThe sum of ";
	x.write(cout);
	cout << " and ";
	y.write(cout);
	cout << " is ";
	z.write(cout);
	cout << endl;
	
	return 0;
}

time24::time24(int h , int m)
{
	hour_ = h;
	minute_ = m;
}

void time24::write(ostream &out)
{
	out << hour_ << ":" << minute_ / 10 << minute_ % 10;
}

time24 time24::add(const time24 &y) const
{
	int hr_sum, min_sum;
	
	hr_sum = hour_ + y.hour_;
	if(hr_sum >= 24) 
		hr_sum = hr_sum - 24;
	
	min_sum = minute_ + y.minute_;
	if(min_sum >=60)
	{
		min_sum = min_sum - 60;
		hr_sum++;
	}
	
	time24 z(hr_sum, min_sum);
	
	return z;
}

