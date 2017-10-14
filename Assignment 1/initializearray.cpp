/*File: initializearray.cpp
  This program uses a number of different functions to initialize an array.
  
  Programmer:  Erin Aucoin
  Student ID:  B00631829
  Date:        September 8, 2017
  */
  
  #include<iostream>
  #include<fstream>
  using namespace std;
  
  //prototypes
  float * init();
  float * init(int n);
  float * init(int n, float val);
  
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

float* init()
{
	float * x = new float[1];
	x[0] = 0.0;
	return x;
}

/*Function: init
  This function initializes an array with a specified size, n, and the 
  values stored in the array set to a specified value, val.
*/

float * init(int n)
{
	float * x = new float[n];
	for(int i=0; i<n; i++)
	x[i] = 0.0;
	return x;
}

/*Function: init
  This function initializes an array with a specified size, n, and the 
  values stored in the array set to 0.0
*/

float * init(int n, float val)
{
	float * x = new float[n];
	for(int i=0; i<n; i++)
	x[i] = val;
	return x;
}

