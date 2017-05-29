/* Exercise 13.1.3 - 13.13 */

#include <iostream>
#include <memory>

using namespace std;

struct X {
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
};

void do_nothing(struct X c)
{
    cout << "do_nothing(struct X c)" << endl;
}

void do_nothing_ref(struct X &d) 
{
    cout << "do_nothing_ref(struct X &d)" << endl;
}

int main()
{
    struct X a;
    struct X b(a);

    do_nothing(a);
    do_nothing_ref(b);

    struct X *c = new struct X(a);
    
    delete c;

    return 0;
}
