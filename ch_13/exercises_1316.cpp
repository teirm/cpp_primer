/* Exercises 13.1.6 */

#include <string>
#include <iostream>

using namespace std;

class Employee {
public:
    Employee(string s):name(s), myId(++id) { cout << "Basic Constructor" << endl;}
    Employee(Employee &e):name(e.name), myId(++id) { cout << "Copy constructor" << endl; }
    Employee& operator=(Employee &e); 
    int getId() { return this->myId; }
private:
    string name;
    int myId;
    static int id;
};

// Need to init the static variable
int Employee::id = 0;

Employee& Employee::operator=(Employee &e)
{
    cout << "In = " << endl;
    this->name = e.name;
    this->myId = e.myId;

    return *this;
}


int main()
{
    Employee head("Bob");

    Employee vice(head);

    Employee fish("doggos");
    fish = head;

    cout << "Head id: " << head.getId() << endl;
    cout << "Vice id: " << vice.getId() << endl;
    cout << "Fish id: " << fish.getId() << endl;
    return 0;
}
