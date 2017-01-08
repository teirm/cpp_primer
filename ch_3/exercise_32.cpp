/* Exercise 3.2
 * Purpose: Read in input word by word
 * and output input to stdout
 */

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void display_ex(string exercise)
{
    string underscore(exercise.size(), '-'); 
    
    cout << "\n" << exercise << "\n" <<
        underscore << endl;
}

void perform_io()
{
    string word;

    /* To read in entire lines
     * use getline(cin, line) */
    
    while (cin >> word) {
        cout << word << endl;
    }
}

void equality_test(const string s1, const string s2)
{
    if (s1 == s2) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are not equal" << endl;
    }
}

void length_test(const string s1, const string s2)
{
    string result; 
    
    if (s1.size() == s2.size()) {
        result = "EQUAL";
    } else if (s1.size() > s2.size()) {
        result = "S1 IS LARGER";
    } else {
        result = "S2 IS LARGER";
    }

    cout << result << endl;
}

void check_two_strings()
{
    string s1;
    string s2;

    cin >> s1 >> s2;

    equality_test(s1, s2);

    length_test(s1, s2);

}

void concat_strings()
{
    string word;
    string text_body; 

    while (cin >> word) {
        text_body += word;
    }

    cout << text_body << endl;
}

int main() 
{
    display_ex("Exercise 3.4");
    check_two_strings();

    /* Only 3.5 or 3.2 can be run at
     * any given compilation since CTRL-D
     * is used to termininate IO 
     */

    display_ex("Exercise 3.5");
    concat_strings();
    
    display_ex("Exercise 3.2");
    perform_io(); 

    return 0;
}
