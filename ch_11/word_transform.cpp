/* Word Transform program from 11.3.6 */

#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

map<string, string>
buildMap
(
    ifstream &map_file
)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) { 
        if (value.size() > 1)
//            trans_map[key] = value.substr(1);
            trans_map.insert({key, value.substr(1)});
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string &
transform
(
    const string &s,
    const map<string, string> &m
)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}


void
word_transform
(
    ifstream &map_file,
    ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else 
                cout << " ";
            cout << transform(word, trans_map); // print output
        }
        cout << endl;
    }
}

int
main
(
    int argc,
    char **argv
)
{
    if (argc != 3) {
        cout << "Usage: ./word_transform <rules_file> <text_file>" <<endl;
        return 1;
    }

    ifstream rules(argv[1]);
    ifstream input(argv[2]);
   
    word_transform(rules, input);

    return 0;
}


