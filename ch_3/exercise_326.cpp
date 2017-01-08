/* Exercise 3.2.6
 * Purpose: Section Exercises
 */

#include <iostream>
#include <string>

#include "../tools/display_ex.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void x_ify()
{
    string input;

    cin >> input;

    for (char &c: input) {
        c = 'X';
    }

    cout << input << endl;
}


void remove_punctuation()
{
    string input;

    cin >> input;

    for (auto &c: input) {
        if (ispunct(c)) {
            c = '\0';
        }
    }

    cout << input << endl;
}

int main()
{
    display_ex("Exercise 3.6");
    x_ify();

    display_ex("Exercise 3.8");
    remove_punctuation();

    return 0;
}
