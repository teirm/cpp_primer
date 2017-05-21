
#include <iostream>
#include <vector>
#include <string>

#include "StrBlob.H"

using namespace std;

typedef vector<string>::size_type size_type;

int main()
{
    string input;
    StrBlob myStrBlob;
    StrBlobPtr myPtr(myStrBlob);


    while (cin >> input) {
        myStrBlob.push_back(input);
    }
    
    for (size_type i = 0; i < myStrBlob.size(); ++i) {
        cout << myPtr.deref() << endl;
        myPtr.incr();
    }


    return 0;
}
