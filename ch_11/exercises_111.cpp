/* exercises for section 11.1 */

#include <map>
#include <utility> // for pair
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int print_map(map<string, int> &m)
{
    for_each(m.begin(), m.end(),
                [](pair<string, int> p) { cout << p.first << " occured "
                                          << p.second << " times." << endl;});

    return 0;
}

int word_count(const string &file_name)
{
    fstream ifp(file_name);
    
    if (!ifp) {
        cerr << "Error: could not open file" << endl;
        return 1; 
    }

    string input;
    map<string, int> words; 
    while (ifp >> input) {
        ++words[input];     
    }

    print_map(words);

    return 0;
}

int lowercase_and_strip_punc(string &s)
{
    set<char> punc = {'.', ',', '?', '`', '\"', '!'};

    for (string::size_type i = 0; i < s.size(); ++i) {
        if (punc.find(s[i]) != punc.end()) {
            s.erase(i, 1);
        }
    }

    transform(s.begin(), s.end(), s.begin(), ::tolower);
     
    return 0;
}


int word_count_nop(const string &file_name)
{
    fstream ifp(file_name);
    
    if (!ifp) {
        cerr << "Error: could not open file" << endl;
        return 1; 
    }
    
    string input;
    map<string, int> words;
    while (ifp >> input) {
        lowercase_and_strip_punc(input);
        ++words[input];
    }

    print_map(words);

    return 0;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        cerr << "Usage: ./exercises_111 file_name [nop]" << endl;
        return 1; 
    }
    
    int rc = 0;
    
    if (argc == 3 && strcmp(argv[2], "nop") == 0) {
        rc = word_count_nop(argv[1]);
    } else {
        rc = word_count(argv[1]);
    }

    return rc;
}

