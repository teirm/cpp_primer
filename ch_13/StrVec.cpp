/* StrVec class implementation from 13.5 */

#include "StrVec.H"

#include <iostream>
#include <algorithm>

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements; /* empty */) {
            alloc.destroy(--p);
        }

        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> init_list) {
    for (std::string s : init_list) {
        this->push_back(s);
    }
}


StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(const size_t n)
{
    if (n > this->capacity()) {
        auto newcapacity = n;
        auto newdata = alloc.allocate(newcapacity);

        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
}



size_t StrVec::resize(const size_t n, const std::string &s)
{
    if (n > this->capacity()) { 
        std::string insert; 
        if (!s.empty()) {
            insert = s;
        }
        for (size_t i = 0; i < n; ++i) {
            this->push_back(insert);
        }
    } else if (n < this->capacity()) {
        size_t deletions = this->size() - n;
        for (size_t i = 0; i < deletions ; ++i) {
            alloc.destroy(--first_free);
        }
    } else {
        /* n == capacity: NO OP */
    }
    
    return this->capacity();
}
