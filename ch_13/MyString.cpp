/* Implementation of MyString */

#include "MyString.H"

std::allocator<char> MyString::alloc;

MyString::MyString(char *s)
{
    size_t input_size = std::strlen(s);
    elements = alloc.allocate(input_size+1);
    
    for (size_t i = 0; i < input_size; ++i) {
        elements[i] = *s++;
    }

    elements[input_size+1] = '\0';
    first_free = elements + input_size;
    cap = elements + input_size;
}


void MyString::free() {

    if (elements) {
        for (auto p = first_free; p != elements; /* empty */)
            alloc.destroy(--p);
    }

    alloc.deallocate(elements, cap - elements);
}


std::pair<char *, char *>
MyString::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}


MyString::~MyString()
{
    free();
}

