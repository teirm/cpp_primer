#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {

    friend std::istream &read(std::istream &is, Person &p);
    friend std::ostream &print(std::ostream &os, const Person &p);

public:
    Person() = default;
    Person(const std::string name, const std::string address);
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }

private:
    std::string address;
    std::string name;
};

Person::Person(const std::string in_name, const std::string in_address)
{
    name = in_name;
    address = in_address;
}


std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

#endif
