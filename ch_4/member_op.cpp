/* Interator vector member operation
 * test 
 */

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector<string> my_strings;

    my_strings.push_back("Doggos");
    my_strings.push_back("Kittens");


    vector<string>::iterator str_it =  my_strings.begin();
    cout << str_it++->empty() << endl;


    return 0;
}
