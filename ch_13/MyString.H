/* A simplified String Class */

#ifndef MYSTRING_GUARD
#define MYSTRING_GUARD

#include <memory>
#include <cstring>
#include <utility>
#include <iostream>

class MyString {
public:
    MyString():
        elements(nullptr), first_free(nullptr), cap(nullptr) { };
    MyString(char *);
    MyString(const MyString&);
    MyString(MyString&&) noexcept;
    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&) noexcept;
    ~MyString();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }
private:
    static std::allocator<char> alloc;
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    char *elements;
    char *first_free;
    char *cap;
};

#endif
