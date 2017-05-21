/* Exercises for section 12.1.5 */

#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> p0(new int(2048));

    unique_ptr<int> p1;
    
    p1.reset(p0.release());
   
    int ix = 1024;
    int *pi = &ix;
    int *pi2 = new int(2048);

    unique_ptr<int> r2(pi2);
    unique_ptr<int> r0(r2.get());


    return 0;
}
