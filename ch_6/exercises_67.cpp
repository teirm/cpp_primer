/* Using function pointers */

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int func(int a, int b);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }


int main()
{
    typedef int (*f)(int a, int b);

    vector<f> arithmetic;
   
    arithmetic.push_back(add);
    arithmetic.push_back(sub);
    arithmetic.push_back(mult);
    arithmetic.push_back(divide);

    for (vector<f>::iterator b = arithmetic.begin();
            b != arithmetic.end(); b++) {
        cout << (*b)(1,3) << endl;
    }
    return 0;
}
