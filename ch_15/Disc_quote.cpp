/* Implementation of Discoute Quote class */

#include "Quote.H"

Disc_quote& Disc_quote::operator=(const Disc_quote &dq)
{
    Quote::operator=(dq);
    quantity = dq.quantity;
    discount = dq.discount;

    return *this;
}

Disc_quote& Disc_quote::operator=(Disc_quote &dq)
{
    Quote::operator=(dq);
    quantity = dq.quantity;
    discount = dq.discount;

    return *this;
}
