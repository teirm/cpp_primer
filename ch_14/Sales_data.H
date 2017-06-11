/* Struct for Sales Data */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
class Sales_data {

friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::istream &operator>>(std::istream&, Sales_data&);
friend std::ostream &operator<<(std::ostream&, const Sales_data&);
friend bool operator==(const Sales_data&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &); 
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(std::string&);
    explicit operator double() const { return revenue; }
    operator std::string() const { return bookNo; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
std::istream& operator>>(std::istream&, const Sales_data&);
Sales_data& operator+(Sales_data&, Sales_data&);
bool operator==(const Sales_data&, const Sales_data&);
bool operator!=(const Sales_data&, const Sales_data&);
#endif
