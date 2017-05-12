/* Exercises for section 10.3.2 */

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>


using namespace std;

auto g = [] (const int i, const int j) { return i + j; };


int lambda_add_five(const int i)
{
   int j = 5;
    
   auto f = [j](const int k) { return k + j; };
   
   return f(i); 
}


int main()
{
    cout << lambda_add_five(10) << endl;
    
    return 0;

}

void biggies_two(vector<string> &words,
                 vector<string>::size_type sz)
{
    stable_sort(words.begin(), words.end(),
                [] (const string &a, const string &b)
                   { return a.size() < b.size(); });

    auto last_true = partition(words.begin(),
                               words.end(),
                               [sz] (const string &a)
                               {return a.size() >= sz; });

    for_each(words.begin(), last_true,
            [](const string &s) { cout << s << " "; });

    cout << endl;
}


