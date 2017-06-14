/* Test program for Quote.H */

#include <iostream>

#include "Quote.H"

using namespace std;

double print_total(ostream &os,
                   const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote myQuote("Doggos", 2.00);
    Bulk_quote myBQuote("Cattos", 3.00, 9, 0.50);

    print_total(cout, myQuote, 10);
    print_total(cout, myBQuote, 10);

    return 0;
}



