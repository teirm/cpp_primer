/* Exercise 3.3.3
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

int sum_pairs()
{
    int input = 0;
    int sum = 0; 

    vector<int> vec_i;
    vector<int>::size_type i;

    while (cin >> input) {
        vec_i.push_back(input);
    }

    for (i = 0; i < vec_i.size() - 1; i ++) {
        sum = vec_i[i] + vec_i[i+1];
        cout << sum << endl;
    }
    
    return 0;
}

int sum_ends()
{
    int input = 0;
    int sum = 0;

    vector<int> vec_i;
    vector<int>::size_type i;
    vector<int>::size_type iterations;

    while (cin >> input) {
        vec_i.push_back(input);
    }

    vec_i.size() % 2 == 0 ?
        iterations = vec_i.size()/2 :
        iterations = vec_i.size()/2 + 1;

    for (i = 0; i < iterations; i++) {
        sum = vec_i[i] + vec_i[vec_i.size() - i - 1];
        cout << sum << endl;
    }

    return 0;
}

int main()
{
    display_ex("Exercise 3.20 a");
    sum_pairs();

    display_ex("Exercise 3.20 b");
//    sum_ends();

    return 0;
}
