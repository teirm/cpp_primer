/* Exercises for 10.3.1 */

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool longer_than_five(const string &s)
{
    return s.length() <= 5;
}

int main()
{
    vector<string> s_vec = {"doggos", "cats", "dogs",
                            "fish", "kittens", "moop",
                            "blep", "blorps"};

    vector<string>::iterator last_true = partition(s_vec.begin(), s_vec.end(), longer_than_five);

    for (vector<string>::iterator it = s_vec.begin(); it != last_true; ++it) {
        cout << *it << endl;
    }

    return 0;
}


