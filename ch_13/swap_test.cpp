/* A test program for the swap function */

#include "HasPtr.H"
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    HasPtr dog("dog");
    HasPtr cat("cat");
    HasPtr fish("fish");

    vector<HasPtr> hp_vec;
   
    for (int i = 0; i < 1000; ++i) {
        hp_vec.push_back(dog);
        hp_vec.push_back(cat);
        hp_vec.push_back(fish);
        hp_vec.push_back(cat); 
    }

    cout << (dog < cat) << endl;

    /* for small ranges, sort will do insertion sort */
    sort(hp_vec.begin(), hp_vec.end());

    return 0;
}
