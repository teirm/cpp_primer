#include "RefCountHasPtr.H"

RefCountHasPtr::~RefCountHasPtr()
{
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

RefCountHasPtr& RefCountHasPtr::operator=(const RefCountHasPtr &rp)
{
    ++*rp.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }

    ps = rp.ps;
    i = rp.i;
    use = rp.use;
    return *this;
}
