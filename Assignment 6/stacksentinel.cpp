/* File: stacksentinel.cpp
   This program implements a simple stack of integers using a linked list
   with a sentinel
 
   Programmer:  Erin Aucoin
   Student ID:  B00631829
   Date:        October 20, 2017
*/

#include <iostream>
#include <fstream>
using namespace std;

class node {
	
friend class stack; 		// stack needs access to node’s members

private:
	int data; 				// this is the data in a stack node
	node *next; 			// pointer to the next stack node

public:
	node(int x); 			// data = x, next = NULL
};

class stack {
private:
	node sentinel; 						// sentinel for the stack
	
public:
	stack(void); 						// constructor
	void push(int x);
	int pop(void);
	bool empty(void) const; 			// check for empty stack
	void write(ostream &out) const; 	// write the stack to out
};

int main()
{
	stack mystack;
	ofstream fout ("stacksentinelout.txt");
	char ch;
	int x;
	
	cout << "A dynamic stack of integers\n";
	fout << "A dynamic stack of integers\n";
	do {
		// print a little menu
		cout << "\n\np = push \n";
		cout << "o = pop\n";
		cout << "s = print to screen\n";
		cout << "f = print to file\n";
		cout << "q = quit\n\n";
		
		cin >> ch;

		if (ch =='p') {
			cout <<"\ndata to push :";
			cin >> x;
			mystack.push(x);
		}
		else if(ch == 'o') {
			if(mystack.empty()) {
				cout << "Stack is empty\n";
			} else {
				cout << "\n\ndata popped : " << mystack.pop();
			}
		}
		else if(ch == 's') mystack.write(cout);
		else if(ch == 'f') mystack.write(fout);
	
	}while(ch != 'q');

	fout.close();
	return 0;
}

node::node(int x)
{
	data = x;
	next = NULL;
}

stack::stack() : sentinel(0)
{
	
}

void stack::push(int x)
{
	node* ptr;
	
	ptr = new node(x);				// make ptr point to a new node storing x
	
	ptr->next = sentinel.next;		// connect *ptr into the list
	sentinel.next = ptr;			// make ptr the new first of list
}

int stack::pop()
{
	
	int temp = 0;					// return 0 if stack is empty
	
	if(sentinel.next != NULL){
		temp = sentinel.next->data;		// hold onto this value until the end
		node* ptr = sentinel.next;		// remember the top of the stack
		
		sentinel.next = sentinel.next-> next;		// move the top to the next node in the list
		delete ptr;						// release the memory used by the old top
	}
	return temp;
}

bool stack::empty() const
{
	return(sentinel.next == NULL);
}

void stack::write(ostream& out) const
{
	node* ptr = sentinel.next;			// ptr will move down the list
	
	while(ptr != NULL) {
		out << ptr -> data << ", ";		// print the data
		ptr = ptr -> next;				// move one position down the line
	}
	
	out << endl;
}
