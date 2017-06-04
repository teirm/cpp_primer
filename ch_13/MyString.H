/* A simplified String Class */

#ifndef MYSTRING_GUARD
#define MYSTRING_GUARD

#include <memory>
#include <cstring>
#include <utility>

class MyString {
public:
    MyString():
        elements(nullptr), first_free(nullptr), cap(nullptr) { };
    MyString(char *);
    MyString(const MyString&);
    MyString& operator=(const MyString&);
    ~MyString();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; } 
private:
    static std::allocator<char> alloc;
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void reallocate();
    void free();
    char *elements;
    char *first_free;
    char *cap;
};

#endif
