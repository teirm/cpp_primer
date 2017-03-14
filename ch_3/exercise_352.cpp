/* Exercises for Section 3.5.2 */

#include <iostream>
#include <vector>

#include "../tools/display_ex.cpp"

using namespace std;

int ten_ints() 
{
    int arr[10] = {};

    for (size_t i; i < 10; i++) {
        arr[i] = 10;
    }

    for (auto x : arr) {
        cout << x << endl;
    }

    return 0;
}

int copy_ints()
{
    int arr[10] = {};
    int barr[10];

    for (size_t i = 0; i < 10; i++) {
        arr[i] = i;
    }

    for (size_t i = 0; i < 10; i++) {
        barr[i] = arr[i];
    }

    for (auto x:barr) {
        cout << x << endl;
    }

    return 0;
}

int main()
{
    display_ex("Exercise 3.31");
    ten_ints();

    display_ex("Exercise 3.32");
    copy_ints();


    return 0;
}
