/* Exercises for Section 3.4.2 */

#include <iostream>
#include <vector>

#include "../tools/display_ex.cpp"

using namespace std;

int both_sides_adder() {
    
    vector<int> v1{1,2,3,4,5,6,7,8,9};
    
    auto beg = v1.cbegin();
    auto end = v1.cend();
    auto mid = beg + (end - beg) / 2;

    while (beg != mid) {
        cout << *(--end) + *beg++ << endl;
    }

    if (v1.size() % 2 == 1) {
        cout << *mid + *mid << endl;
    }

    return 0;
}


int grades_clustering()
{
    /* Not reading in the grades from standard in */ 
    vector<int> grades{10,20,31,41,2,10,99,100};
    vector<int> frequencies(11);

    for (auto it = grades.cbegin(); it != grades.cend(); it++) {
        ++frequencies[*it/10];
    }

    for (auto it = frequencies.cbegin(); it != frequencies.cend(); it++) {
        cout << *it << endl;
    }

    return 0;
}


int main()
{
    display_ex("Exercise 3.24");
    both_sides_adder();

    display_ex("Exercise 3.25");
    grades_clustering();

    return 0;
} 
