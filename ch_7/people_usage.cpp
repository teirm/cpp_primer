/* A small program to use the people class */

#include <iostream>
#include <string>

#include "Person.H"

using namespace std;

int main(int argc, char **argv)
{
    string name = "Doggo";
    string address = "123 Doggy Lane";

    Person dogPerson = Person(name, address);

    cout << dogPerson.get_name() << endl
         << dogPerson.get_address() << endl;

    return 0;
}
