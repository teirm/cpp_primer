/* A small program to get back in shape
 * after an unecessarily long hiatus
 */

#include <iostream>

using namespace std;

int main()
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    
    cout << "Inital values for the variables are: " << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Variable " << i << " is ";

        switch(i) {
            case 0: 
                cout << "x1 " << x1 << endl;
                break;
            case 1:
                cout << "x2 " << x2 << endl;
                break;
            case 2:
                cout << "y1 " << y1 << endl;
                break;
            case 3:
                cout << "y2 " << y2 << endl;
                break;
        }
    }

    cin >> x1;
    cout << "x1 is now " << x1 << endl;
    
    cin >> x2;
    cout << "x2 is now " << x2 << endl;

    cin >> y1;
    cout << "y1 is now " << y1 << endl;

    cin >> y2;
    cout << "y2 is now " << y2 << endl;

    int sum_1 = x1 + y1;
    int sum_2 = x2 + y2;

    cout << "sum of 1s is " << sum_1 << endl;
    cout << "sum of 2s is " << sum_2 << endl;

    if (sum_1 > sum_2) {
        cout << "Sum of 1s is larger" << endl;
    } else if (sum_1 < sum_2) {
        cout << "Sum of 2s is larger" << endl;
    } else {
        cout << "The sums are equal" << endl;
    }

    int counter = 0;
    while (counter < 4) {
        counter++;
    }

    int average = (sum_1 + sum_2) / counter;

    cout << "Average is " << average << endl;

    return 0;
}
