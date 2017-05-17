/* Exercises 11.3.2 */

#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int 
store_family(
multimap<string, string>    &mm,
const string                &family_name,
const vector<string>        &children)
{
    for (string child : children) {
        mm.insert({family_name, child});
    }

    return 0;
}

int main()
{
    vector<string> smiths = {"sally", "susan"};
    vector<string> clarks = {"bill", "flosten", "helga", "harmonie"};
    vector<string> adams = {"clarissa", "demios"};

    multimap<string, string> family_map;
    
    store_family(family_map, "smiths", smiths);
    store_family(family_map, "clarks", clarks);
    store_family(family_map, "adams", adams);


    multimap<string, string>::const_iterator it = family_map.cbegin();

    while (it != family_map.cend()) {
        cout << "Family Name: " << it->first
             << " Child: " << it->second << endl;
        ++it;
    }

    return 0;
}
