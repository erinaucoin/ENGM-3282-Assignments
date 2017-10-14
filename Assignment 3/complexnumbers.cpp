/* File: complexnumbers.cpp
   Implement complex numbers as a class using operators 
   
   Programmer:  Erin Aucoin
   Student ID:  B00631829
   Date:        September 29, 2017
*/

#include <iostream>
#include <fstream>

using namespace std;

class complex {
private:
	float x; // real part
	float y; // imaginary part
	
public:
	complex(float re = 0.0, float im = 0.0); // constructor
	float real(void) const; // return real part
	float imag(void) const; // return imag part
	void real(float re); // set real part
	void imag(float im); // set imag part
};

////////////////////// prototypes of complex operators //////////////////////

istream& operator>> (istream &in, complex &a);   // read a complex number in the form (x,y)
ostream& operator<< (ostream &out, const complex &a);  // write a complex number in the form (x,y)
complex operator+ (const complex &a, const complex &b); // return the sum
complex operator- (const complex &a, const complex &b); // return the difference
complex operator* (const complex &a, const complex &b); // return the product
complex operator/ (const complex &a, const complex &b); // return the quotient

int main(void)
{
	complex a, b, c;

	cout << "Enter two complex numbers in the form (re, im): ";
	cin >> a >> b;

	c = a + b;
	cout << "The sum of " << a << " and " << b << " is " << c << endl;

	c = a - b;
	cout << "The difference of " << a << " and " << b << " is " << c << endl;

	c = a * b;
	cout << "The product of " << a << " and " << b << " is " << c << endl;

	c = a / b;
	cout << "The division of " << a << " and " << b << " is " << c << endl;

	return 0;
}

///////////////////////// implementation of complex ////////////////////

complex::complex(float re, float im)
{
	x = re;
	y = im;
}

float complex::real(void) const
{
	return x;
}

float complex::imag(void) const
{
	return y;
}

void complex::real(float re)
{
	x = re;
}

void complex::imag(float im)
{
	y = im;
}

//////////////////////// implementation of complex operators /////////////

istream& operator>> (istream &in, complex &a)
{
	char discard;
	float h, v;
	in >> discard >> h >> discard >> v >> discard;
	a.real(h);
	a.imag(v);
	return in;
}

ostream& operator<< (ostream &out, const complex &a)
{
	out << "(" << a.real() << "," << a.imag() << ")";
	return out;
}

complex operator + (const complex &a, const complex &b){
	complex s;
	s.real(a.real() + b.real());
	s.imag(a.imag() + b.imag());
	return s;
}

complex operator - (const complex &a, const complex &b){
	complex s;
	s.real(a.real() - b.real());
	s.imag(a.imag() - b.imag());
	return s;
}

complex operator * (const complex &a, const complex &b){
	complex s;
	s.real(a.real()*b.real() - a.imag()*b.imag());
	s.imag(a.real()*b.imag() + a.imag()*b.real());
	return s;
}

complex operator / (const complex &a, const complex &b){
	complex s;
	s.real((a.real()*b.real() + a.imag()*b.imag()) / (b.real()*b.real() + b.imag()*b.imag()));
	s.imag((a.imag()*b.real() - a.real()*b.imag()) / (b.real()*b.real() + b.imag()*b.imag()));
	return s;
}
