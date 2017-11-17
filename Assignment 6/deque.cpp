/* File: deque.cpp
   This program implements a double ended queue of integers as a
   doubly linked list.
 
   Programmer:  Erin Aucoin
   Student ID:  B00631829
   Date:        October 20, 2017
*/

#include <iostream>
#include <fstream>
using namespace std;

class node {
friend class deque;

private:
	int data; 			// this is the data in a list element
	node *next; 		// pointer to the next node in the list
	node *prev; 		// pointer to the previous node in the list

public:
	node(int x); 		// data = x, prev=next = NULL
};

class deque {
private:
	node* front; 		// pointer to the front of the list
	node* back; 		// pointer to the back of the list

public:
	deque(void); 						// constructor of an empty queue
	void put_front(int x); 				// put x at the front of the list
	void put_back(int x); 				// put x at the back of the list
	int get_front(void); 				// get the node at the front of the list
	int get_back(void); 				// get the node at the back of the list
	bool empty(void) const; 			// check for empty deque
	void write(ostream &out) const; 	// write data stored to out
};

int main()
{
	deque mydeque;
	ofstream fout ("dequeout.txt");
	char ch;
	int x;
	
	cout << "A dynamic deque of integers\n";
	fout << "A dynamic deque of integers\n";
	
	do {
		// print a little menu
		cout << "\n\n1 = put front \n";
		cout << "2 = put back \n";
		cout << "3 = get front\n";
		cout << "4 = get back\n";
		cout << "s = print to screen\n";
		cout << "f = print to file\n";
		cout << "q = quit\n\n";
		
		cin >> ch;
		
		if (ch == '1') {
			cout <<"\ndata to put front:";
			cin >> x;
			mydeque.put_front(x);
		}
		else if (ch == '2') {
			cout <<"\ndata to put back:";
			cin >> x;
			mydeque.put_back(x);
		}
		else if(ch == '3') {
			if(mydeque.empty()) {
				cout << "deque is empty\n";
			} else {
				cout << "\n\ndata gotten : " << mydeque.get_front();
			}
		}
		else if(ch == '4') {
			if(mydeque.empty()) {
				cout << "deque is empty\n";
			} else {
				cout << "\n\ndata gotten : " << mydeque.get_back();
			}
		}
		else if(ch == 's') mydeque.write(cout);
		else if(ch == 'f') mydeque.write(fout);
		
	}while(ch != 'q');
	
	fout.close();
	return 0;
}

node::node(int x)
{
data = x;
next = NULL;
prev = NULL;
}

deque::deque()
{
}

void deque::put_front(int x)
{
	node* ptr = new node(x);	// create a new node with data x -- next component of this node is set to NULL in node constructor
	
	if(front == NULL) {			// so is back -- deque is empty (special case)
		back = front = ptr;		// make ptr both front and back
	}
	else {						//general case
		ptr -> prev = front;
		front -> next = ptr;
		front = ptr;
	}
}

void deque::put_back(int x)
{
	node* ptr = new node(x);	// create a new node with data x -- next component of this node is set to NULL in node constructor
	
	if(front == NULL) {			// so is back -- deque is empty (special case)
		back = front = ptr;		// make ptr both front and back
	}
	else{
		ptr -> next = back;
		back -> prev = ptr;
		back = ptr;		
	}
}

int deque::get_front(){
	if(front == NULL)
		return 0;
	
	int temp;
	node * ptr;

	if(front == back) {   		// only one element in the deque (special case)
		temp = front -> data;
		delete front;			//delete the only node
		front = back = NULL;	//update front and back -- deque is now empty
	}
	else{						//general case
		ptr = front -> prev;
		ptr -> next = NULL; 
		temp = front -> data;
		delete front;
		front = ptr;
	}
	return temp;
}

int deque::get_back(){
	if(front == NULL)
		return 0;
	
	int temp;
	node* ptr;
	
	if(front == back){			// only one element in the deque (special case)
		temp = back -> data;
		delete back;			//delete the only node
		front = back = NULL;	//update front and back -- deque is now empty
	}
	else{						//general case
		ptr = back -> next;
		ptr -> prev = NULL;
		temp = back -> data;
		delete back;
		back = ptr;
	}
	return temp;
}

bool deque::empty() const
{
	return (front == NULL);
}

void deque::write(ostream& out) const
{
	node* ptr = back;					// ptr will move down the list
	
	while(ptr != NULL) {
		out << ptr -> data << ", ";		// print the data
		ptr = ptr -> next;				// move one position down the line
	}
	
	out << endl;
}

