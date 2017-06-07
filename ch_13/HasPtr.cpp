/* Exercises for 13.1.2 */

#include "HasPtr.H"
HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if (this != &rhs) {
        delete this->ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}
