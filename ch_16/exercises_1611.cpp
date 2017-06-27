/* Exercises from section 16.1.1 */

#include <string>
#include <iostream>

#include "Sales_data.H"

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}


template <class T, typename U>
int find(
        const T         &beg,
        const T         &end,
        U               key)
{
    for (; beg != end; ++beg) {
        if (*beg == key) {
            return 1;
        }
    }

    return 0;
}


template <typename T, unsigned N>
void print(const T (&a1)[N])
{
    for (T i : a1) {
        cout << i << endl;
    }
}

template <typename T, unsigned N> constexpr 
int array_len(const T (&a1)[N])
{
    return N;
}

int main()
{
    Sales_data sd1("dogs");
    Sales_data sd2("dogs");

//  will not compile due to missing < operator
//    cout << compare(sd1, sd2) << endl;

    int a2[30];
    for (int i = 0; i < 30; i++) {
        a2[i] = i*i;
    }

    int a3[40];
    for (int i = 0; i < 40; i++) {
        a3[i] = i*i*i;
    }

    print(a3);
    print(a2);

    cout << array_len(a3) << endl;

    return 0;
}
