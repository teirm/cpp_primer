/* Exercises for 13.1.2 */

#include "HasPtr.H"

HasPtr& HasPtr::operator=(const HasPtr &h)
{
    ps = new std::string(*h.ps);
    i = h.i;
}
