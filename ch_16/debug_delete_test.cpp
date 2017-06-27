/* A test program for debug delete */

#include <memory>

#include "DebugDelete.H"

using namespace std;

int main()
{
    double* p = new double;
    DebugDelete d;
    d(p);

    unique_ptr<double, DebugDelete> q(new double, DebugDelete());


    return 0;
}

