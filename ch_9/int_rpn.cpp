/* Basic RPN adder */

#include <stack>
#include <string>
#include <iostream>

#include <stdio.h>

using namespace std;

int main()
{
    string value;

    stack<int> calc;

    while (cin >> value) {
        if (value == "+") {
            int v1 = calc.top();
            calc.pop();
            int v2 = calc.top(); calc.pop();
            calc.push(v1+v2);
        } else {
            int ivalue = stoi(value);
            calc.push(ivalue);
        }
    }

    printf("Final sum: %d", calc.top());

    return 0;
}
