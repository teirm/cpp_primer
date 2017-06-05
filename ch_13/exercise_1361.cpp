/* Exercise 13.6.1 on Moving Objects */

#include <vector>
#include "MyString.H"

using namespace std;

int f() {
    return 3;
}
vector<int> vi(100);

int &&r1 = f();
int &r2 = vi[0];
int &r3 = r1;
int &&r4 = vi[0] * f();

int main()
{
    vector<MyString> ms_vec;
    MyString s((char *)"Doggos");

    for (int i = 0; i < 100; ++i) {
        ms_vec.push_back(s);
    }

    return 0;
}
