/* Implementation of the Quote Class */

#include "Quote.H"

Quote& Quote::operator=(const Quote &rhs)
{
    this->price = rhs.price;
    this->bookNo = rhs.bookNo;
    
    return *this;
}

Quote Quote::operator=(Quote &&rhs)
{
    if (this != &rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;
    }

    return *this;
}

