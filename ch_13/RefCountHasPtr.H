/* Class Reference Counted HasPtr */

#include <string>

class RefCountHasPtr {
public:
    RefCountHasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    RefCountHasPtr(const RefCountHasPtr &h):
        ps(new std::string(*h.ps)), i(h.i), use(h.use) {}
    RefCountHasPtr& operator=(const RefCountHasPtr&);
    ~RefCountHasPtr(); 
private:
    std::string *ps;
    int i;
    std::size_t *use;
};
