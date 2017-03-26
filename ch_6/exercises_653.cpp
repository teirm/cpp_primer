/* Recursive vector print
 * with debugging 
 */

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;


void print_vec(auto b, auto e)
{
    cerr << "Debug: " << __FILE__
         << " : in function " << __func__ 
         << " at line " << __LINE__ << endl
         << "       Compiled on " << __DATE__
         << " at " << __TIME__ << endl
         << "       Value of begin: " <<  *b << endl
         << "       Value of end:   " <<  *e << endl;             
    
    if (b == e) {
        return;
    } else {
        cout << *b++ << endl;
        print_vec(b,e);
    }
}



int main() {

    vector<int> vec_a = {0,1,2,3,4,5,6,7,8,9};
    vector<int>::iterator beg = vec_a.begin();
    vector<int>::iterator end = vec_a.end();



    print_vec(beg, end);
    return 0;
}
