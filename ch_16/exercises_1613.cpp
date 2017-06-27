/* exercises for section 16.1.3 */

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_container(const vector<T> &v)
{
    for (typename vector<T>::size_type i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}

template <class U>
void print_iterators(const U &v2)
{
    for (typename U::const_iterator b = v2.cbegin(); b != v2.cend(); ++b) {
        cout << *b << endl;
    }
}


int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8};

    print_container<int>(v);
    print_iterators<vector<int>>(v);

    return 0;
}
