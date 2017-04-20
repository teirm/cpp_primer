/* Exercise 9.2.7 */

#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

using namespace std;

bool compare_vec(const vector<int> &v1, const vector<int> &v2)
{
    return v1 == v2;
}

int compare_containers(const vector<int> &v1, const list<int> &l1)
{
    int comparison = 0;
    if (v1.size() == l1.size()) {
        int v_counter = 0;
        /* all variables in a for loop must have same base type */
        for (list<int>::const_iterator l_it = l1.cbegin(); l_it != l1.cend(); l_it++) {
            if (v1[v_counter] > *l_it) {
                comparison = -1;
                break;
            }
        
            if (v1[v_counter] < *l_it) {
                comparison = 1;
                break;
            }

            v_counter++;
        }
    
        return comparison; 
    }
    

    vector<int>::size_type count = 0;
    for (const int &i : l1) {
        if (v1[count] != i) {
            comparison = v1[count] - i;
            return comparison; 
        }
        count++;
        // we might index beyond the list and hence
        // get junk
        if (count >= v1.size()) {
            break;
        }
    }

    if (v1.size() < l1.size()) {
        return -1;
    }
    
    return 1;
}

int main()
{
    list<int> l1 = {0,1,2,3,4};
    vector<int> v1 = {0,1,2,3,4};

    cout << "Identical containers" << endl;
    assert(compare_containers(v1,l1) == 0);
    cout << "Identical containers passed" << endl;

    l1 = {0,1,2,3};
    v1 = {0,1,2,3,4};

    cout << "longer vector" << endl;
    assert(compare_containers(v1,l1) == 1);
    cout << "longer vector passed" << endl;

    l1 = {0,1,2,3,4,5};
    v1 = {0,1,2,3,4};

    cout << "Longer list " << endl;
    assert(compare_containers(v1,l1) == -1);
    cout << "Longer list passed" << endl;
    
    return 0;
}
