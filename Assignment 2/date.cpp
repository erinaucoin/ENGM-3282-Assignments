/*File: date.cpp
  A class representing dates in the form: day, month and year
  
  dates are written to a stream in the form day/month/year
  
  day_number() returns the number of days since 1/1 of the current year
  including the current day
  
  days_between() returns the number of days between two dates not
  including the firstday but including the last day.


  Programmer:  Erin Aucoin
  Student ID:  B00631829
  Date:        September 22, 2017
*/

#include <iostream>
#include <fstream>
using namespace std;

class date {
private:
	int day;
	int month;
	int year;
public:
	date(int d, int m, int y);		// constructor
	date write(ostream &out);		// prints day/month/year to out
	int day_number() const;				// calculates and returns day number
	int days_between(date &a) const;
};

// number of days in each month
const int DAYS[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(void)
{
	ofstream fout("date.txt");
	date d(12, 6, 2010);
	date e(14, 9, 2012);
	
	fout << "For the date is ";
	d.write(fout);
	fout << endl;
	
	fout << "Day number is " << d.day_number() << endl;
	
	fout << "\nFor the date is ";
	e.write(fout);
	fout << endl;
	
	fout << "Day number is " << e.day_number() << endl;
	
	fout << "\nDays between ";
	d.write(fout);
	fout << " and ";
	e.write(fout);
	fout << " = " << d.days_between(e) << endl;
	
	fout.close();
	return 0;
}

date::date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

date date::write(ostream &out)
{
	out << day << "/" << month << "/" << year;
}

int date::day_number() const
{
	int num;
	
	num = day;
	
	for(int i=0; i < month - 1; i++)
	{
		num = num + DAYS[i];
	}
	
	return num;
}

int date::days_between(date &a) const
{
	int days_between;
	//int years[];
	
	// calculate the days between the day of year
	days_between = day_number() - a.day_number();
	// calculate the days between the years
	days_between = days_between + 365 * (year - a.year);
	
	// fix negative values
	if(days_between <0)
		days_between = -1 * days_between;
	
	// add days for leap years
	
	return days_between;
}
