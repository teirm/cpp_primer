/* Exercise 15.13 */

#include <string>
#include <ostream>

using namespace std;

class base {
public:
    string name() { return basename; }
    virtual void print (ostream &os) { os << basename; }
private:
    string basename;
};

class derived: public base {
public:
    void print(ostream &os) override { base::print(os); os << " " << i; } 
private:
    int i;
};

