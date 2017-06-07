/* Class Foo from 13.6 */

#ifndef FOO_GUARD
#define FOO_GUARD

#include <vector>
#include <iostream>
#include <algorithm>

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}


#endif 
