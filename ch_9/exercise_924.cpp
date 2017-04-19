/* Exercise 9.2.4 */


#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> i_vec = {1,2,3,4,5,6};
    vector<double> d_vec(i_vec.begin(), i_vec.end());

    for (double &x: d_vec) {
        cout << "Value in d_vec: " << x << endl;
    }

    return 0;
}
    
