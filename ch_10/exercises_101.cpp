/* Exercises 10.1 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int count_vals(int value, const vector<int> &v) {

    return count(v.begin(), v.end(), value);

}

int main()
{

    vector<int> v1 = {1,2,3,4,5,6,1,2,3,1,0};

    cout << count_vals(1, v1) << endl;

    return 0;
}
