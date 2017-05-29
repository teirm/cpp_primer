/* Exercises 13.1.4 */

#include <iostream>

using namespace std;

class numbered {
public:
    numbered():mysn(0) {}
    numbered(numbered &n):mysn(n.mysn+1) {}
    numbered& operator=(numbered &n) { mysn = n.mysn+1; return *this;}
    int mysn;
};

void f (const numbered s) { cout << s.mysn << endl; }

int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    
    return 0;
}

