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


MyString::MyString(const MyString &s)
{
    std::cout << "MyString::MyString(const MyString &s)" 
              << std::endl; 
    size_t input_size = s.size();
    elements = alloc.allocate(input_size);
    
    for (size_t i = 0; i < input_size; ++i) {
        this->elements[i] = s.elements[i];
    }
    
    this->elements[input_size] = '\0';
    first_free = elements + input_size;
    cap = elements + input_size;
}

MyString::MyString(MyString &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    elements = first_free = cap = nullptr;
}


MyString& MyString::operator=(MyString &&rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free= rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

MyString& MyString::operator=(const MyString &rhs)
{
    std::cout << "MyString::operator=(const MyString &rhs)" 
              << std::endl; 
    
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
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

