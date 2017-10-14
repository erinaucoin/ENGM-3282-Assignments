/*File: initializearraydefaults.cpp
  This program uses a function with default arguments to initialize an array.
  
  Programmer:  Erin Aucoin
  Student ID:  B00631829
  Date:        September 15, 2017
  */
  
  #include<iostream>
  #include<fstream>
  using namespace std;
  
  //prototype
  float * init(int n = 1, float val = 0.0);
  
  int main(void)
  {
  	float* x;
  	float val;
  	int n;
  	
  	n=1;
  	x=init();
  	
  	cout << "\nx = \n";
  	for(int i=0; i<n; i++)
	{
  		cout << x[i] << endl;
	}
	
	delete [] x;
	
	n=4;
	x=init(n);
	  
	cout << "\nx = \n";
	for(int i=0; i< n; i++)
	{
		cout << x[i] << endl;
	}
	  
	delete [] x;
	
	n=5;
	val=1.27;
	x = init(n, val);
	
	cout << "\nx = \n";
	for(int i=0; i<n; i++)
	{
		cout << x[i] << endl;
	}
	
	delete [] x;
	
	return 0;
  }
  
/*Function: init
  This function initializes an array with an unspecified size, so it is 
  initialized to 1 and the values stored in the array set to 0.0
*/

float* init(int n, float val)
{
	float * x = new float[1];
	for(int i=0; i<n; i++)
	{
		x[i] = val;
	}
	return x;
}

