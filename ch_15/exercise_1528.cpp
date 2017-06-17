/* Exercise 15.28 */

#include <vector>
#include <memory>
#include <iostream>
#include <numeric>

#include "Quote.H"

using namespace std;

int main()
{
    vector<shared_ptr<Quote>> bulk_basket;

    bulk_basket.push_back(make_shared<Bulk_quote>("0-201-82470-1", 50, 20, 0.50));
    bulk_basket.push_back(make_shared<Bulk_quote>("0-201-82470-1", 50, 20, 0.50));
    bulk_basket.push_back(make_shared<Bulk_quote>("0-201-82470-1", 50, 20, 0.50));
    bulk_basket.push_back(make_shared<Bulk_quote>("0-201-82470-1", 50, 20, 0.50));

    double bulk_sum = 0.0;
   
    for (auto &bq : bulk_basket) { 
        bulk_sum += bq->net_price(21);
    }

    cout << "The sum of elements in bulk_basket is: " << bulk_sum << endl;


    return 0;
}

