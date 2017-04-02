/* Exercise 8.1,2 */

#include <iostream>
#include <string>

using namespace std;

istream &check_stream(istream &is)
{
    string input;

    while (is >> input) {
        cout << input << endl;
    }

    if (is.eof()) { cout << "EOF" << endl; }
    if (is.fail()) { cout << "FAIL" << endl; }
    if (is.good()) { cout << "GOOD" << endl; }
    if (is.bad()) { cout << "BAD" << endl; }
         
    is.clear();

    return is;
}


int main()
{
    check_stream(cin);

    return 0;
}
