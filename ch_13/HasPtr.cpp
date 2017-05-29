/* Exercises for 13.1.2 */

#include "HasPtr.H"

HasPtr& HasPtr::operator=(const HasPtr &h)
{
    auto newp = new std::string(*h.ps);
    delete ps;
    ps = newp; 
    i = h.i;
    return *this;
}
