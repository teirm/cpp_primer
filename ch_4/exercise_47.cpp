/* Exercises 4.7 */

#include <iostream>
#include <vector>

#include "../tools/display_ex.cpp"

using namespace std;

int double_odds()
{
    vector<int> int_vec;

    for (int i = 0; i < 10; i++) {
        int_vec.push_back(i);
    }

    for (int &v: int_vec) {
        cout << "Original: " << v;
        v = (v % 2 == 0) ? v : v *2;
        cout << " New: " <<  v << endl;
    }
   

    return 0;
}

int main()
{
    display_ex("Exercise 4.21");
    double_odds();
    return 0;
}
