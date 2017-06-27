/* Exercises for section 16.3 */

#include <iostream>

using namespace std;

template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);

template <typename T>
void f(T t)
{
    cout << "template <typename T> void f(T)" << endl;
    cout << t << endl;
}

template <typename T>
void f(const T* t)
{
    cout << "template <typename T> void f(const T*)" << endl;
    cout << *t << endl;
}

template <typename T>
void g(T t)
{
    cout << "template <typename T> void g(T)" << endl;
    cout << t << endl;
}

template <typename T>
void g(T* t)
{
    cout << "template <typename T> void g(T*)" << endl;
    cout << *t << endl;
}


int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42); // g(T t)
    g(p); // g(T* t)
    g(ci); //g(T t)
    g(p2); // g(T* t)

    f(42); // f(T t)
    f(p);  // f(T t) T -> int*
    f(ci); // f(T t)
    f(p2); // f(const T*)

    return 0;

}
