/* A Test program for the StrVec Class */


#include <iostream>
#include "StrVec.H"

#define INSERTS 10

using namespace std;

int main()
{
    StrVec s;

    s.push_back("dogs");
    
    for (int i = 0; i < INSERTS; ++i) { 
        s.push_back("cats");
    }

    cout << "The Capacity is: " << s.capacity()
         << endl;

    s.reserve(300);
    
    cout << "The Capacity is: " << s.capacity()
         << endl;

    s.resize(3);

    for (string *b = s.begin(); b != s.end(); b++) {
        cout << *b << endl;
    }

    return 0;
}
