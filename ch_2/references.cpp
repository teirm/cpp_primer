#include <iostream>

int main() {

//    int i = 0;
//    int &r1 = i;

    double d = 0;
    double &r2 = d;

    int i, &ri = i;
    i = 5; ri = 10;

    std::cout << i << " " << ri << std::endl;
    return 0;
}
