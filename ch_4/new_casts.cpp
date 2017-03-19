/* Trying a named cast */

#include <iostream>

using namespace std;

int main()
{
    int j = 10;
    int i = 3;

    double slope = static_cast<double>(j/i);

    cout << slope << endl;

    return 0;
}
