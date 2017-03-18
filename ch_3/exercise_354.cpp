/* Exercises 3.5.4 */

#include <iostream>
#include <vector>

#include "../tools/display_ex.cpp"

#define EQUAL 1
#define NOT_EQUAL 0

using namespace std;


int not_null_term()
{
    const char ca[] = {'h','e','l','l','o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp++ << endl;
    }
    return 0;
}

int compare_strings()
{
    const char *ca = "dogs";
    const char *cb = "dogss";

    for ( ; *ca == *cb; ca++, cb++) {    
        if (*ca == '\0') {
            cout << 0 << endl;
            return 0; 
        }
    }
    
    cout << *ca - *cb << endl;

    return 0;
}

int main()
{
    display_ex("Ex 3.37");
    not_null_term();

    display_ex("Ex 3.39");
    compare_strings();


    return 0;
}
