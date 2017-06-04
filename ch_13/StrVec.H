/* StrVec class from 13.5 */

#ifndef STRVEC_GUARD
#define STRVEC_GUARD

#include <string>
#include <utility>
#include <memory>
#include <initializer_list>

class StrVec {
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    StrVec(std::initializer_list<std::string> init_list); 
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    size_t resize(const size_t, const std::string& s="");
    void reserve(const size_t);
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

#endif
