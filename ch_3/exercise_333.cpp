/* Exercise 3.3.3
 * Purpose: Section Exercises
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "../tools/display_ex.cpp"

using std::cout;
using std::cin;
using std::endl;

using std::string;

using std::vector;

int uppercase_vector()
{
    string input;

    vector<string> vec_s;

    while (cin >> input) {
        vec_s.push_back(input);
    }

    for (auto &elem : vec_s) {
        for (auto &c : elem) {
            cout << (char)toupper(c);
        }
        cout << endl;
    }

    return 0;
}

int main ()
{

    display_ex("Exercise 3.17");
    uppercase_vector();

    return 0;
}

