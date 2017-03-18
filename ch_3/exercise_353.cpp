/* Exercises 3.5.3 */

#include <iostream>
#include <vector>

#include "../tools/display_ex.cpp"

#define EQUAL 1
#define NOT_EQUAL 0

using namespace std;

int set_zero()
{
    int a[10];
    int *b = begin(a);
    int *e = end(a);

    while (b != e) {
        *b++ = 0; 
    }

    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    return 0;
}

int compare_arrays()
{
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};

    int *begin_a = begin(a);
    int *begin_b = begin(b);

    int *end_a = end(a);
    int *end_b = end(b);

    /* flag variable */
    int equality = EQUAL;
    while (begin_a != end_a && begin_b != end_b) {
        if (*begin_a++ != *begin_b++) {
            equality = NOT_EQUAL;
            break;
        }
    }
   
    /* Check that b reached the end */
    if (begin_b != end_b) {
        equality = NOT_EQUAL;
    }

    /* check that a reached the end */
    if (begin_a != end_a) {
        equality = NOT_EQUAL;
    }

    cout << equality << endl;

    return 0;
}


int main()
{
    
    display_ex("Exercise 3.35");
    set_zero();

    display_ex("Exercise 3.36");
    compare_arrays();

    return 0;
}
