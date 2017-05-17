/* Exercises for section 11.2.3 */

#include <vector>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

int read_into_pair(vector<pair<string,int>> &p_vec)
{
    int count = 0;
    string input = ""; 
    string s_val = "";
    int i_val = 0;
    while (cin >> input) {
        if (count % 2 == 1) {
            i_val = stoi(input);
            p_vec.push_back(make_pair(s_val, i_val));
            count = 0;
        } else {
            s_val = input;
            ++count;
        }
    }

    return 0;
}

int main()
{
    vector<pair<string, int>> p_vec;

    read_into_pair(p_vec);

    for (pair<string, int> p : p_vec) {
        cout << p.first << ":" << p.second << endl;
    }

    return 0;
}
