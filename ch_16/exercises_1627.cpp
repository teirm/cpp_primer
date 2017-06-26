/* Exercises for section 16.2.7 */

#include <utility>
#include <iostream>

using namespace std;

class Test {
public:
    template <typename F, typename T1, typename T2>
    void flip(F f, T1 &&t1, T2 &&t2)
    {
        f(std::forward<T2>(t2), std::forward<T1>(t1));
    }
};


void f(int a, int b)
{
    cout << "A" << a << endl;
    cout << "B" << b << endl;
}


int main()
{
    Test t;
    
    int a = 3;
    int b = 2;

    t.flip(f, a, 2);

    return 0;
}



    
