/* Exercises 2.30 and 2.31 */

#include <iostream>

using namespace std;

int main()
{
    int i = 0;

    const int v2 = 0;
    int v1 = v2;
    
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &i, &r2 = v2; 

    /* Checking validity */
    r1 = v2;
    cout << "Value of r1 " << r1 << endl;

    //p1 = p2;
    //p1 = p3;

    p2 = p1;
    p2 = p3;

    return 0;
}
