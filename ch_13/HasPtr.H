/* Exercises for 13.1.1 */

#include <string>
#include <iostream>

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &h):
        ps(new std::string(*h.ps)), i(h.i) {}
    HasPtr& operator=(const HasPtr&);
    bool operator<(const HasPtr &b) { return *b.ps < *this->ps; }
    ~HasPtr() { delete this->ps; }
private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
    std::cout << "Calling Swap" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
