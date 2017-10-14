/*File: minmaxd.cpp
  This program uses two functions with to find the maximum and minimum of a set of 
  floats stored in the file minmax.txt.  This program uses a dynamically allocated 
  array.
  
  Programmer:  Erin Aucoin
  Student ID:  B00631829
  Date:        September 15, 2017
*/
  
#include<iostream>
#include<fstream>
using namespace std;
  
void readdata(float *x, int &n);
void minmax(float *x, int n, float &max, float &min);

int main(void)
{
	ofstream outfile("minmaxdout.txt");
	
	float* x; // pointer to the array
	int n; // the actual array size
	float max; // the maximum
	float min; // the minimum
	
	// read the data into the array
	readdata(x, n);
	
    //compute the maximum and minimum 
	minmax(x, n, max, min);
	
	delete [] x;
	
	outfile << "The array has " << n << " elements\n";
	outfile << "The maximum value in the array is " << max << endl;
	outfile << "The minimum value in the array is " << min << endl;
	
	outfile.close();
	
	return 0;
}

void readdata(float *x, int &n)
{
	ifstream fin("minmax.txt");
	
	fin >> n;
	x = new float[n];
	
	for(int i = 0; i < n; i++) fin >> x[i];
	fin.close();
}

void minmax(float *x, int n, float &max, float &min)
{
	max = x[0];
	min = x[0];
	
	for(int i=0; i<n; i++)
	{
		if(x[i] < min) min = x[i];
		if(x[i] > max) max = x[i];
	}
}
