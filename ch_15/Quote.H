/* Quote classes */

#ifndef QUOTE_GUARD
#define QUOTE_GUARD

#include <string>

class Quote {
public:
    Quote();
    Quote(const Quote &q):
        bookNo(q.bookNo), price(q.price) { }        
    Quote(Quote &&q) noexcept:
        bookNo(q.bookNo), price(q.price) { }
    Quote& operator=(const Quote&);
    Quote operator=(Quote&&);
    virtual ~Quote() = default;
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() &&
        { return new Quote(std::move(*this)); }
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
            { return n * price; }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const Disc_quote &dq):
        Quote(dq), quantity(dq.quantity), discount(dq.discount) { }
    Disc_quote(Disc_quote &&dq):
        Quote(dq), quantity(dq.quantity), discount(dq.discount) { }
    Disc_quote& operator=(const Disc_quote&);
    Disc_quote& operator=(Disc_quote&);
    Disc_quote(
        const std::string       &book,
        double                  price,
        std::size_t             qty,
        double                  disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const Bulk_quote &bq):
        Disc_quote(bq) { }
    Bulk_quote(Bulk_quote &&bq):
        Disc_quote(bq) { }
    Bulk_quote& operator=(const Bulk_quote &bq)
        { Disc_quote::operator=(bq); return *this; };
    Bulk_quote& operator=(Bulk_quote &bq)
        { Disc_quote::operator=(bq); return *this; };
    Bulk_quote* clone() const &
        { return new Bulk_quote(*this); }
    Bulk_quote* clone() &&
        { return new Bulk_quote(std::move(*this)); }
    Bulk_quote(
        const std::string&      book,
        double                  sales_price,
        std::size_t             qty,
        double                  discount):
        Disc_quote(book, sales_price, qty, discount) { }
    double net_price(std::size_t) const override;
};

#endif
