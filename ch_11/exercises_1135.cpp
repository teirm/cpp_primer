/* Exercises for section 11.3.5 */

#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void alphabetical_print(multimap<string, string> &mm)
{
    for (const pair<string, string> p : mm) {
        cout << "First: " << p.first
             << " Second: " << p.second << endl;
    }
}


int main()
{
    multimap<string, string> author_map;
    
    vector<string> authors = {"Zamiyatin", "Chekhov", "Chaucer", "Tolstoy"};
    
    for (string &author : authors) {
        author_map.insert({author, "Ward No. 6"});
        author_map.insert({author, "The Grasshopper"});
    }
    
    int erased = author_map.erase("Chekhov");

    cout << "The number erased: " << erased << endl;

    alphabetical_print(author_map);

    return 0;
}
