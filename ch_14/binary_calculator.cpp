/* A binary calculator example */

#include <map>
#include <functional>

using namespace std;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) { return i % j; };
struct divide {
    int operator() (int numerator, int divisor) {
        return numerator / divisor;
    }
};

map<string, function<int(int, int)>> binops = {
    {"+", add},
    {"-", std::minus<int>()},
    {"/", divide()},
    {"*", [](int i, int j) { return i * j; }},
    {"%", mod} 
};


