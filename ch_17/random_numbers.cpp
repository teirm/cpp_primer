/* Skimming Section 17.4 */

#include <random>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

void seed_generators()
{
    default_random_engine e1;
    default_random_engine e2(13190192301);
    default_random_engine e3;
    e3.seed(1231231231);
    default_random_engine e4;
    
    uniform_int_distribution<unsigned> u(0,100);


    for (size_t i = 0; i < 1000000000000; ++i) {
        cout << "Iteration: " << i << endl;

        if (u(e1) == u(e2)) { 
            cout << "unseeded match at iteration: " << i << endl;
            break;
        }
        if (u(e4) == u(e4)) {
            cout << "Seeded match at iteration: " << i << endl;
            break; 
        }
    }
}

void normal_dist()
{
    default_random_engine e(time(0));
    normal_distribution<> n(4,1.5);
    int *values = new int[9];
   
    cout << "Length of array: " << 
         sizeof values / sizeof(*values) << endl;

    for (size_t i = 0; i < 1000000; ++i) {
        unsigned v = lround(n(e));
        if (v < 9) {
            ++values[v];
        }
    }

    for (size_t i = 0; i < 9; ++i) {
        string s(values[i]/10000, '*');
        cout << i << "(" << values[i] << "): " << s << endl;
    }
    
    delete[] values;
}

int main()
{
    /* seed_generators(); */
    normal_dist();
        
    return 0;
}


