/* Exercises for section 10.2.2 */

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int zero_vec(vector<int> &vec, int count)
{
    auto it = back_inserter(vec);
    fill_n(it, count, 0);

    return 0;
}


/* Exercise for 10.2.3 */

void print_str_vector(const vector<string> &v)
{
    for (string s : v) {
        cout << s << endl;
    }
}


void elim_dups(vector<string> &words)
{
    sort(words.begin(), words.end());
    cout << "After Sort" << endl;
    print_str_vector(words);

    auto end_unique = unique(words.begin(), words.end());
    cout << "After Unique" << endl;
    print_str_vector(words);


    words.erase(end_unique, words.end());
    cout << "After Erase" << endl;
    print_str_vector(words);
}

int main()
{
    vector<int> my_numbers;
    zero_vec(my_numbers, 20);
   
    for (int i : my_numbers) {
        cout << i << endl;
    }

    vector<string> words = {"the", "quick", "red",
                            "fox", "jumped", "over",
                            "the", "slow", "red",
                            "turtle"};

    elim_dups(words);

    return 0;
}
