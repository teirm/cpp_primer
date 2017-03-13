/* Exercises section 3.4.1
 * 12 MAR 2017
 */

#include <iostream>
#include <vector>
#include <string>

#include "../tools/display_ex.cpp"

using namespace std;


int iterating_vectors()
{

    vector<int> v1(10, 1);

    for (auto it = v1.cbegin();
            it != v1.cend(); it++) {
        cout << *it << endl;
    }

    return 0;
}

int uppercase_text()
{
    string some_text = "This is a walrus";

    for (auto it = some_text.begin();
            it != some_text.end(); it++) {
        *it = toupper(*it);
    }

    cout << some_text << endl;

    return 0;
}

int double_elements()
{

    vector<int> v2;

    for (int i = 2; i < 21; i++) {
        v2.push_back(i);
    }

    for (auto it = v2.begin();
            it != v2.end(); it++) {
       
        cout << *it << "\t";
        *it *= 2;
        cout << *it << endl;
    }

    return 0;
}



int main() 
{
    display_ex("Exercise 3.21");
    iterating_vectors();

    display_ex("Exercise 3.22");
    uppercase_text();

    display_ex("Exercise 3.23");
    double_elements();


    return 0;
}
