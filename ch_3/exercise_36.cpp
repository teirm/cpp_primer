/* Exercise 3.6 */

#include <iostream>

using namespace std;

int main()
{
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };

    cout << "Printing with For Each Loops" << endl;
    for (const int (&row)[4]: ia) {
        for (int val: row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nPrint with indicies" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }
   
    cout << "\nPrinting with iterators" << endl;
    int (*b_outer)[4] = begin(ia);
    int (*e_outer)[4] = end(ia);

    for ( ; b_outer != e_outer; b_outer++) {
        int *b_inner = begin(*b_outer);
        int *e_inner = end(*b_outer);
        for ( ; b_inner != e_inner; b_inner++) {
            cout << *b_inner << " ";
        }
        cout << endl;
    }

    return 0;
}
