/* Exercises for section 12.1.2 */

#include <memory>
#include <vector>
#include <iostream>

#include <cstdlib>
#include <cstdio>

using namespace std;

vector<int>* make_vector()
{
    return new vector<int>();
}

void fill_vector(vector<int> *v)
{
    int x = 0;
    while (cin >> x) {
        v->push_back(x);
    }
}

void print_vector(vector<int> *v)
{
    for (int x : *v) {
        cout << x << endl;
    }

    delete v;
}

int main()
{
    vector<int>* v = make_vector();
    printf("The address of vector v is after creation: %p", v);

    fill_vector(v);

    print_vector(v);
    printf("The address of vector v is after deletion: %p", v);

    return 0;
}
