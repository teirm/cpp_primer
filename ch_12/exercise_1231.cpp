/* Exercises 12.3.1 */

#include "TextQuery.H"
#include <iostream>
using namespace std;

void runQueries(ifstream &ifp) 
{
    TextQuery tq(ifp);

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;

        if (!(cin >> s) || s == "q") break;
        tq.queryWord(s).print();
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        cout << "Usage: ./exercise_1231 file" << endl;
        return 1; 
    }

    ifstream ifp(argv[1]);

    runQueries(ifp);

    return 0;
}
