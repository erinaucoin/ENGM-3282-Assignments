/* File: employeetypes.cpp
   Program to illustrate derived classes.
 
   Programmer:  Erin Aucoin
   Student ID:  B00631829
   Date:        November 2, 2017
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class employee {
private:
    string name;  // last name
    int id;       // employee id number
    float salary; // employee salary
    
public:
    employee(string n="none", int i=0, float s=0.0);
    void write(ostream &out);
    void read(istream &in);
};

class manager : public employee {  
private:
    string title;       // vice-president etc
public:
    manager(string n="none", int i=0, float s=0.0, string t="none");
    void write(ostream &out);
    void read(istream &in);
};

class scientist : public employee{  
private:
    int pubs;           // number of publications

public:
    scientist(string n="none", int i=0, float s=0.0, int p=0);
    void write(ostream &out);
    void read(istream &in);
};

class labourer : public employee {    
private:
    string dept;
      
public:
    labourer(string n="none", int i=0, float s=0.0, string d="none");
    void write(ostream &out);
    void read(istream &in);
};

int main()
{
    string type;            // employee type
    ofstream fout ("employeetypesout.txt");

    while(1) { // loop until break occurs
        cout << "\n\nType of employee: "; cin >> type;
        if (type == "q") break;

        if(type == "labourer") {     
            labourer lab;
            lab.read(cin);

            cout << "\n";
            lab.write(cout);
            fout << "\n";
            lab.write(fout);

        } else if (type == "scientist") { 
            scientist sci;
            sci.read(cin);

            cout << "\n";
            sci.write(cout);
            fout << "\n";
            sci.write(fout);

        } else if (type == "manager") {        
            manager man;
            man.read(cin);

            cout << "\n";
            man.write(cout);
            fout << "\n";
            man.write(fout);

        }        
   }
   fout.close();   
   return 0;
}

///////////////// Member functions of employee /////////////////////////////

employee::employee(string n, int i, float s)
{
    name = n;
    id = i;
    salary = s;
}
void employee::write(ostream &out)
{

    out << "name  : " << name <<   "\n";
    out << "id    : " << id  <<    "\n";
    out << "salary: " << salary << "\n";
}
void employee::read(istream &in)
{
    if(in == cin) { // give a prompt to the user
        cout << "name  : ";
    }
    in >> name;

    if(in == cin) { // give a prompt to the user
        cout << "id  : ";
    }
    in >> id;
    
    if(in == cin) { // give a prompt to the user
        cout << "salary: ";
    }
    in >> salary;
}      
//////////////////// Member functions of labourer /////////////////////////

labourer::labourer(string n, int i, float s, string d) : employee(n, i, s)
{
	dept = d;
}

void labourer::write(ostream& out)
{
	out << "type  : labourer";
	employee::write(out);
	out << "department : " << dept << "\n"; 
}

void labourer::read(istream& in)
{
	employee::read(in);
	if(in==cin){
		cout <<"department : ";
	}
	in >> dept;
}

//////////////////// Member functions of manager ///////////////////////////

manager::manager(string n, int i, float s, string t) : employee(n, i, s)
{
	title = t;
}

void manager::write(ostream& out)
{
	out << "type  : manager";	
	employee::write(out);				// prints name, id and salary
	out << "title : " << title << "\n";	//prints title
}

void manager::read(istream& in)
{
	employee::read(in);
	if(in==cin){
		cout << "title : ";
	}
	in >> title;
}


//////////////////// Member functions of scientist ////////////////////////

scientist::scientist(string n, int i, float s, int p)
{
	pubs = p;
}

void scientist::write(ostream& out)
{
	out << "type  : scientist";	
	employee::write(out);
	out << "number of publications : " << pubs << "\n"; 
}

void scientist::read(istream& in)
{
	employee::read(in);
	if(in==cin){
		cout <<"number of publications : ";
	}
	in >> pubs;
}
