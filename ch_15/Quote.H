/* Quote classes */

#ifndef QUOTE_GUARD
#define QUOTE_GUARD

#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
            { return n * price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(
        const std::string&      book,
        double                  sales_price,
        std::size_t             qty,
        double                  discount):
        Quote(book, sales_price), min_qty(qty), discount(discount) { }
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

#endif
