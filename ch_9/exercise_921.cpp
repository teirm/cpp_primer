
/* Finding an element */

#include <vector>
#include <iostream>

using namespace std;


bool search(
        vector<int>::iterator beg,
        vector<int>::iterator end,
        const int value
) {
    while (beg != end) {
        if (*(beg++) == value) {
            return true;
        }
    }
    return false;
}



int main()
{
    vector<int> numbers;

    for (int i = 0; i < 20; i++) {
        numbers.push_back(i);
    }

    cout << search(numbers.begin(), numbers.end(), 4) << endl;

    return 0;

}
