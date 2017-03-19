/* A small program to see what happens
 * if you refer and modify a variable
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i = 0;
    /* Operation ++i is undefined */
    /* -Wsequence-point */
    cout << i << " " << ++i << endl;

    return 0;
}

