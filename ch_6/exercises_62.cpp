/* Exercises from Chapter 6
 * Section 2
 */

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

#include "../tools/display_ex.cpp"

using namespace std;

int pointer_swap(int *i, int *j)
{
    int temp = 0;

    temp = *i;
    *i = *j;
    *j = temp;

    return 0;
}


int reset(int &k) 
{
    k = 0;
    return 0;
}


int ref_swap(int &a, int &b)
{
    int temp = 0;

    temp = a;
    a = b;
    b = temp;

    return 0;
}

int swap_pointers(int **i, int **j)
{
    int *temp = nullptr;
    
    temp = *j;
    *j = *i;
    *i = temp;

    return 0;
}

int print_list(initializer_list<int> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        cout << *beg << endl;
    }

    return 0;
}


int main(int argc, char **argv)
{
    display_ex("Exercise 6.10");
    int x = 1;
    int y = 2;
    cout << "Before Swap: x=" << x <<
        " y=" << y << endl;
    pointer_swap(&x, &y);
    cout << "After Swap: x=" << x <<
        " y=" << y << endl;

    display_ex("Exercise 6.11");
    int z = 10;
    cout << "Before reset: z=" << z << endl; 
    reset(z);
    cout << "After reset: z=" << z << endl; 

    display_ex("Exercise 6.12");
    cout << "Before Swap: x=" << x <<
        " y=" << y << endl;
    ref_swap(x, y);
    cout << "After Swap: x=" << x <<
        " y=" << y << endl;

    display_ex("Exercise 6.22");
    int *a = &x;
    int *b = &y;
    cout << "Before Swap: *a=" << *a <<
        " *b=" << *b << endl;
    swap_pointers(&a, &b);
    cout << "After Swap: *a=" << *a <<
        " *b=" << *b << endl;

    if (argc > 1) {
        string s1 = argv[1];
        string s2 = argv[2];
        
        cout << "Arg 1 " << s1 << endl;
        cout << "Arg 2 " << s2 << endl;
        
        cout << "Concatenated " << s1 + s2 << endl;

    } else {
        cout << "Must provide arguments" << endl;
    }

    
    print_list({1,2,3,4,5,6,7,8,9,10});


    return 0;
}
