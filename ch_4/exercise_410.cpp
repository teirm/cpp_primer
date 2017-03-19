/* A difference between post fix and infix */

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> ivec = {1,2,3,4,5,6,7};

    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0;
            ix != ivec.size(); ix++, cnt--) {
        cout << "ix: " << ix << endl;
        cout << "cnt: " << cnt << endl;
        ivec[ix] = cnt;
    }

    return 0;
}
        
