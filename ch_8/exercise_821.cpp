/* file operations */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    string file_name = argv[1];
    string word;
    
    vector<string> line_holder;


    ifstream in(file_name);

    while (in >> word) {
        line_holder.push_back(word); 
    }

    in.close();

    for (string &s: line_holder) {
        cout << s << endl;
    }

    return 0;
}
