/* Exercises 10.4.1 */

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

int unique_to_list(vector<int> &i_vec, list<int> &i_list)
{
    if (i_list.size() != 0) {
        cerr << "Error: " << endl 
             << "File: " << __FILE__ << endl
             << "Function: " << __func__ << " at " << __LINE__ << endl
             << "\tInput list should be empty.  List size was: " << i_list.size() << endl;
    
        return -1; 
    }
   

    sort(i_vec.begin(), i_vec.end());

    // unique requires a sorted container
    unique_copy(i_vec.begin(), i_vec.end(), back_inserter(i_list));

    return 0;
}

int main()
{
    vector<int> i_vec = {1,2,3,1,2,3,1,2,3};
    list<int> i_list;

    int rc = unique_to_list(i_vec, i_list);

    for_each(i_list.begin(), i_list.end(),
                [](const int i) { cout << i << endl;});    

    return rc;
}
