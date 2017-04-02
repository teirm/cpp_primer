/* Exercise section 8.3.2
 * Using stringstreams
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char **argv)
{
    string line, word;
    vector<PersonInfo> people;

    fstream in(argv[1]);

    while (getline(in, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;

        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }


    for (PersonInfo &p : people) {
        cout << "Name: " << p.name << endl;
        for (string &num: p.phones) {
            cout << "Number: " << num << endl;
        }
    }

    return 0;
}
