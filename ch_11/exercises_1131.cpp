/* Exercises for section 11.3.1 */

#include <map>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int zero_map(map<int, int> &m)
{
    map<int, int>::iterator it = m.begin();

    while (it != m.end()) {
        it->second = 0;
        ++it;
    } 
    return 0;
}

int main()
{
    map<int, int> my_ints;
    
    my_ints[1] = 2;
    my_ints[3] = 3;
    my_ints[4] = 5;
    
    zero_map(my_ints);

    map<int, int>::const_iterator c_it = my_ints.cbegin();
    
    while (c_it != my_ints.cend()) {
        cout << "First: " << c_it->first
             << "\tSecond: " << c_it->second
             << endl;
        ++c_it;
    }

    return 0;
}
