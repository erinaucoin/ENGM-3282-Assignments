/* File: singleserver.cpp
   Implemet a standard single server queue.
 
   Programmer:  Erin Aucoin
   Student ID:  B00631829
   Date:        October 27, 2017
*/

#include <iostream>
#include <list>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

bool bernoulli(float prob);

class job {
private:
	int arrive; 				// arrival time
	int start; 					// start time of processing by server
	int finish; 				// finish time = start + service

public:
	job(void); 					// create a job
	void write(ostream &out);

friend class server; 			// server has access to all members of job
};

class server {
private:
	// fill in the appropriate members
	bool busy;					// shows whether the job being processed has finished
	queue<job> q;				// jobs waiting to be processed
	job current;				// job being processed
	list<job> done;				// finished jobs

public:
	server(void); 				// set busy = false
	void process(int t); 		// process at time t
	void report(ostream &out); 	// report the jobs completed to the stream out
};

float lambda = 0.4;
float mu = 0.5;

int main(void)
{
	server srv;
	int n;
	unsigned seed; 				// good value 8478564
	
	cout << "Enter a seed and the number of time steps: ";
	cin >> seed >> n;
	
	srand(seed);
	
	for (int t = 1; t < n; t++) {
		srv.process(t);
	}

	srv.report(cout);
	
	return 0;
}

job::job(void)
{
	arrive = 0;
	start = 0;
	finish = 0;
}

void job::write(ostream &out)
{
	out << setw(6) << arrive << setw(6) << start
	<< setw(6) << finish << endl;
}

server::server()
{
	busy = false;
	// missing some attributes
}

void server::process(int t)
{
	// step 1
	if(busy){
		if(bernoulli(mu)){			// job is finished
			current.finish = t;
			busy = false;
			done.push_back(current);
		}
	}
	
	// step 2
	if(bernoulli(lambda)){
		// an arrival has occured so a new job is created
		job* p = new job;
		
		// set the arrival time of the job to the time t
		p->arrive = t;
		
		// push the job into the queue of waiting jobs
	}
	
	// step 3
	if(!busy  && !q.empty()){
		current = q.front();		// gets the front of the queue
		q.pop();					// removes the job from queue
		current.start = t;			// set start time
	}

	
	
}

void server::report(ostream& out)
{
	
}

bool bernoulli(float prob)
{
	float x = (float) rand() / (float) RAND_MAX;
	return (x < prob);
}

