/* Divide by zero */

#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int i;
    int j;
    int div;

    cin >> i >> j;
    
    try {
        if (j == 0) {
            throw domain_error("Zero divisor\nExiting!\n");
        }
        div = i/j;
    } catch (domain_error err) {
        cout << err.what();
        return -1;
    }
    
    cout << div << endl;

    return 0;
}
