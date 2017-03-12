/* A small program that will
 * output a freqency histogram
 * given a list of integers
 * on [0,100].
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void plot_frequencies(const vector<int> freq) 
{

    cout << "Generating Histogram from frequencies\n" << endl;

    for (vector<int>::size_type i = 0; i < freq.size(); i++) {
        string bin_id = to_string(i) + "\t| "; 
        string row(freq[i], '*');
        cout << bin_id << row << endl; 
    }
}

int main()
{

    int input                         = 0; 
    vector<int>::size_type bins       = 11;
    vector<int> frequencies(bins);

    while (cin >> input) {
        if (input <= 100) { 
            ++frequencies[input/bins];
        }
    }


    cout << "----INPUT COLLECTED----" << endl;

    for (int &v : frequencies) {
        cout << v << endl;
    }

    plot_frequencies(frequencies);

    return 0;
}
