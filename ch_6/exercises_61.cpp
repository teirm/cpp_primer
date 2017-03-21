/* Exercises from Chapter 6
 * section 1
 * 20 March 2017
 */

#include <iostream>

#include "../tools/display_ex.cpp"

using std::cin;
using std::cout;
using std::endl;

int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}

void get_val()
{
    int x;
    cin >> x;

    cout << fact(x) << endl;
}

int abs_value(int a)
{
    if (a < 0) return -a;
    else return a;
}

int static_counter()
{
    static int a = 0;

    return a++;
}

int main()
{
    display_ex("Exercise 6.3");
    int j = fact(10);
    cout << j << endl;


    display_ex("Exercise 6.4");
    get_val();

    int z = abs_value(-31);
    cout << z << endl;
   
    display_ex("Exercise 6.6");
    cout << static_counter() << endl;
    cout << static_counter() << endl;
    cout << static_counter() << endl;
    

    return 0;
}
    

