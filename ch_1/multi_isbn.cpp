#include <iostream>
#include "Sales_item.h"

int main()
{
    int count = 0;
    Sales_item previous_item;
    Sales_item current_item; 

    /* Need to read in at least one item */
    count++;
    std::cin >> previous_item;

    while (std::cin >> current_item) {
        if (previous_item.isbn() == current_item.isbn()) {
            count++;
        } else {
            std::cout << "Number of transactions for ISBN: "
                      + previous_item.isbn() + " equals " << 
                      count << std::endl;
            count = 1;
            previous_item = current_item;
        }
    }

    return 0;
}
