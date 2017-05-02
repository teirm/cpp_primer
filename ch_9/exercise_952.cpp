/* Exercise Section 9.5.2 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int replacer(string &s, string &oldVal, string &newVal)
{

    int match = 0;
    string::size_type pos = 0;

    vector<string::size_type> replacements;
    
    string::iterator it;
    string::iterator replacer;

    string::iterator old_it;

    for (it = s.begin(); it != s.end(); ++it) {

        old_it = oldVal.begin();
        

        if (*old_it == *it) {
            match = 1; 
            for (replacer = it; old_it != oldVal.end(); ++old_it, ++replacer) {
                if (*replacer != *old_it) {
                    match = 0;
                    break;
                }
            }

            if (match == 1) {
                replacements.push_back(pos);
                
                if (pos + oldVal.length() <= s.length()-1) {
                    pos += oldVal.length();
                    it += oldVal.length();
                }
            
            } 
        }
        
        ++pos;
    }

    int offset = 0;
    int difference = newVal.length() - oldVal.length();

    for (string::size_type pos : replacements) {
        cout << pos << endl;
        s.replace(pos+offset, oldVal.length(), newVal);
        offset += difference;        
    }

    cout << s << endl;

    return 0;
}

int main()
{
    string s = "Thru the Thru dogs Thru";
    string oldVal = "Thru";
    string newVal = "Through";

    replacer(s, oldVal, newVal);

    return 0;
}
