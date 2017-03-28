/* A sales data transaction processing program */

#include <iostream>

#include "Sales_data.h"


Sales_data add(const Sales_data& rhs, const Sales_data& lhs)
{
    Sales_data sum = rhs;
    sum.combine(rhs);
    return sum;
}

std::ostream &print(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;

    return os;
}


std::istream &read(std::istream &is, Sales_data& item)
{
    is >> item.bookNo >> item.units_sold >> item.revenue;
    return is;
}
