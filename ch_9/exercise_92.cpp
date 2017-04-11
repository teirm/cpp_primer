/* Using vectors and dequeus */

#include <vector>
#include <deque>

#include <iostream>

using namespace std;

int main() {

    vector<deque<int>> nested;
    int counter = 0;

    for (deque<int> &inner: nested) {
        inner.push_back(counter++);
    }
   

    for (deque<int> &inner: nested) {
        for (int value : inner) {
            cout << value << endl;
        }
    }


    return 0;
}
