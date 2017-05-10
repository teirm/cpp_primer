/* Exercise 10.2.1 */

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int add_ints(const vector<int> &v)
{
     return accumulate(v.cbegin(), v.cend(), 0);
}

int main() {

    vector<int> vec = {1,2,3,4,5,6,7,8,9};

    cout << "Sum is: " << add_ints(vec) << endl;

    return 0;
}
