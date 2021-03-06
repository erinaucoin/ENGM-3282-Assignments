/* File: growingstack.cpp
   This program implements a simple stack of integers which grows as needed.
   
   Programmer:  Erin Aucoin
   Student ID:  B00631829
   Date:        October 13, 2017
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class stack{
private:
    int max;            // maximum size of the stack
    int count;          // number of items on the stack
    int grow;           // data will grow by this amount when needed
    vector<int> data;   // vector holding the stack items

public:
    stack(int sz, int growsz);          // constructor, max = sz, grow = growsz
    
    void push(int item);                // push the integer item onto the stack
    int pop(void);                      // pop an item off the stack
    void write(ostream &out) const;     // send the data stored to out
    bool empty(void) const;             // check for empty stack
};

int main(void)
{
    stack s(5, 4);
    ofstream fout ("growingstackout.txt");
    
    for (int i=1; i <= 15; i++) {
        s.push(i);
    }

    cout << "The stack is:\n";
    s.write(cout);

    fout << "The stack is:\n";
    s.write(fout);

    fout.close();
    return 0;
}

stack::stack(int sz, int growsz) : data(sz)
{
    max = sz;
    grow = growsz;
    count = 0;          // the stack has no entries yet
}

void stack::push(int item)
{
    if(count>max-1)
    {
        max = max + grow;
        cout << "Resizing stack to size: " << max <<endl;
        data.resize(max);
    }

    data[count] = item;
    count++;
}

int stack::pop()
{
    count--;
    return data[count];
}

void stack::write(ostream &out) const
{
    for(int i=0; i<count; i++){
        out << data[i] << ", ";
    }
    
    out << endl;
}

bool stack::empty(void) const
{
    return (count == 0);
}

