/* Exercise 3.3.2
 * Purpose: Section Exercises
 */

#include <iostream>
#include <string>
#include <vector>

#include "../tools/display_ex.cpp"

using std::cout;
using std::cin;
using std::endl;

using std::string;

using std::vector;

int append_ints()
{
    int input = 0;

    vector<int> vec_i;

    while (cin >> input) {
        vec_i.push_back(input);
    }

    for (auto &elem : vec_i) {
        cout << elem << endl;
    }

    return 0;
}

int append_strings()
{
    string input;

    vector<string> vec_s;

    while (cin >> input) {
        vec_s.push_back(input);
    }

    for (auto &elem : vec_s) {
        cout << elem << endl;
    }

    return 0;
}

int main()
{
/*
    display_ex("Exercise 3.14");
    append_ints();
*/

    display_ex("Exercise 3.15");
    append_strings();


    return 0;
}
