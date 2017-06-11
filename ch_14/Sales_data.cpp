/* Implementation of the Sales data class */

#include "Sales_data.H"

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
    
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;

}


std::istream& operator>>(std::istream &is, Sales_data &item)
{
    double price;
    is >> item.bookNo;
    if (is) 
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}

std::istream &read(std::istream &is, Sales_data& item)
{
    is >> item.bookNo >> item.units_sold >> item.revenue;
    return is;
}

Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}


bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return ! (lhs == rhs);
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) 
{
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator=(std::string &isbn)
{
    bookNo = isbn;
    units_sold = 0;
    revenue = 0.0;
    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;   // add members of rhs into
    revenue += rhs.revenue;         // the members of this object
    return *this;                   // return the caller object
}
