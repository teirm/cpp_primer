/* Exercises Section 10.3.3 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int more_than_n(string::size_type n, const vector<string> &s_vec)
{
    return count_if(s_vec.begin(), s_vec.end(),
                    [n](const string &s) { return s.size() > n;});
}


bool lambda_decrement(int input)
{
    // mutable because a lambda cannot change 
    // copied by value by default
    auto f = [input]() mutable -> bool
    { while (input > 0) { --input; cout << input << endl;} return true; };

    return f();
}

int main()
{
    vector<string> s_vec = {"dinosaur", "dog", "cow",
                            "chinchilla", "kittens", "moof",
                            "blep", "doggos", "bow-wow"};

    cout << more_than_n(6, s_vec) << endl;

    lambda_decrement(10); 

    return 0;
}
