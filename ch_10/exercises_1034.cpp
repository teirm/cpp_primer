/* Exercises 10.3.4 */

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int greater_than_length(vector<int> &i_vec, const string &s)
{
    sort(i_vec.begin(), i_vec.end()); 
    auto first_true = find_if(i_vec.begin(), i_vec.end(),
                              bind(check_size, s, _1));

    return *(first_true);
}

int main()
{
    vector<int> i_vec = {1,1,1,1,1,1,1,1,2,3,4,5};

    string s = "dogs";

    cout << greater_than_length(i_vec, s);

    return 0;
}
