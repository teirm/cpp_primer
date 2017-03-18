/* A small program to implement 
 * naive matrix multiplication
 */

#include <iostream>

using namespace std;

int main()
{
    /* Define size */
    int n = 3;

    int ia[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    int id[3][3] = {
            {1,0,0},
            {0,1,0},
            {0,0,1}
    };

    int res[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    }; 

    /* This is too difficult with iterators */
    /* Direct indexing gives neeeded row/col 
     * flexibility 
     */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += ia[i][k] * id[k][j];
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << res[row][col] <<  " ";
        }
        cout << endl;
    }

    return 0;
}

