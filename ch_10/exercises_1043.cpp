/* Exercises for section 10.4.3 */

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int reverse_print(vector<int> &i_vec)
{
    for_each(i_vec.rbegin(), i_vec.rend(),
                [](int i) { cout << i << endl;});

    return 0;
}

int find_zero(vector<int> &i_vec)
{
    auto zero = find(i_vec.rbegin(), i_vec.rend(), 0);

    return *zero;
}

int reverse_copy(vector<int> &i_vec, list<int> &output)
{
    copy(i_vec.rend() - 7, i_vec.rend()-3, front_inserter(output));

    return 0;
}

int main()
{
    vector<int> i_vec = {1,2,3,4,1,2,3,1,3,0,1,2};

    cout << "REVERSE PRINT" << endl;
    reverse_print(i_vec);
    
    cout << "FIND ZERO" << endl;
    cout << find_zero(i_vec) << endl;

    cout << "REVERSE COPY" << endl;
    list<int> empty_list;
    reverse_copy(i_vec, empty_list);
    for_each(empty_list.begin(), empty_list.end(),
                [](int i) { cout << i << endl; });

    return 0;
}
                

