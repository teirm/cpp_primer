/* Looking at some virtual functions */

#include <iostream>

using namespace std;

class Base {
public:
    virtual void fcn()
        { cout << "fcn in Base " << endl; };
};

class D1 : public Base {
public:
    void fcn()
        { cout << "fcn in D1 " << endl; };
    virtual void f2();
};

void D1::f2() {
    cout << "f2 in d1" << endl;
}

class D2 : public D1 {
public:
    int fcn(int);
    void fcn()
        { cout << "fcn in D2 " << endl; };
    void f2();
};

void D2::f2() {
    cout << "f2 in D2" << endl;
}

int main()
{
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj;
    Base *bp2 = &d1obj;
    Base *bp3 = &d2obj;

    bp1->fcn();
    bp2->fcn();
    bp3->fcn();
    
    return 0;
}
