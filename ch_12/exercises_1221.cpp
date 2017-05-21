/* Exercises 12.2.1 */

#include <new>
#include <string>

#include <cstdio>
#include <cstdlib>

using namespace std;

int main() 
{
    string s1 = "Doggos";
    string s2 = "Fishies";

    string::size_type total_length = s1.size() + s2.size() + 1; 

    char* c_arr = new char[total_length];

    int i = 0;

    for (char c : s1) {
        c_arr[i++] = c;
    }

    for (char c : s2) {
        c_arr[i++] = c;
    }

    c_arr[i] = '\0';


    printf("The concatenated string is: %s\n", c_arr);

    delete [] c_arr;

    return 0;
}


