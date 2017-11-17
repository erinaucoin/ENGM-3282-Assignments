/* File: stacq.cpp
   This program implements a cross between a stack and a queue
 
   Programmer:  Erin Aucoin
   Student ID:  B00631829
   Date:        October 20, 2017
*/

#include <iostream>
#include <fstream>
using namespace std;

class node {
friend class stacq;

private:
	int data; 					// this is the data in a stacq element
	node *next; 				// pointer to the next node on the stack
	
public:
	node(int x) {data = x; next = NULL;}
};

class stacq {
private:
	int count; 					// number of values stored
	node* top; 					// pointer to the top of the stacq
	
public:
	stacq(void); 							// constructor of an empty stacq
	void store(int x); 						// store the value x
	int retrieve(void); 					// retrieve a value
	bool empty(void) const; 				// check for empty stack
	void write(ostream &out) const; 		// write stacq to out
};

int main()
{
	stacq mine;
	ofstream fout ("stacqout.txt");
	char ch;
	int x;

	cout << "A dynamic stacq of integers\n";
	fout << "A dynamic stacq of integers\n";

	do {
		// print a little menu
		cout << "\n\ns = store \n";
		cout << "r = retrieve\n";
		cout << "p = print to screen\n";
		cout << "f = print to file\n";
		cout << "q = quit\n\n";

		cin >> ch;

	if (ch == 's') {
		cout <<"\ndata to store :";
		cin >> x;
		mine.store(x);
	}
	else if(ch == 'r') {
		if(mine.empty())
			cout << "empty\n";
		else
			cout << "\n\ndata retrieved :" << mine.retrieve();
	}
	else if(ch == 'p') mine.write(cout);
	else if(ch == 'f') mine.write(fout);

	}while(ch != 'q');

	fout.close();
	return 0;
}

stacq::stacq() : top(0)
{
	count = 0;
}

void stacq::store(int x)
{
	node* ptr;
	
	ptr = new node(x);				// make ptr point to a new node storing x
	
	ptr->next = top;				// connect *ptr into the list
	top = ptr;						// make ptr the new first of list
	
	count++;
}

int stacq::retrieve()
{
	int temp = 0;						// return 0 if stack is empty
	node* ptr = top;					// remember the top of the stack
	
	if(top != NULL){
		if(count %2 != 0) {				// retrieve like a stack				
			temp = top->data;			// hold onto this value until the end
			
			top = top-> next;			// move the top to the next node in the list
		}
		else {							// retreive like a queue
			node* q = top;				// needed to mark the second to last node.
			
			while(ptr->next != NULL) {	// move down the queue until the last node
				q = ptr;
				ptr = ptr->next;
			}
			
			q->next = NULL;				// cut off the last node from the queue
			temp = ptr->data;			// remember the data of the last node
			
			if(ptr == top) {			// we are getting the last node in the queue
				top = NULL;
			}
		}
		count--;		
	}
	
	delete ptr;							// release the memory used by the old top
	
	return temp;
}

bool stacq::empty() const
{
	return (top == NULL);
}

void stacq::write(ostream& out) const
{
	node* ptr = top;					// ptr will move down the list
	
	while(ptr != NULL) {
		out << ptr -> data << ", ";		// print the data
		ptr = ptr -> next;				// move one position down the line
	}
	
	out << endl;
}

