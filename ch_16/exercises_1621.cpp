#include <string>
#include <iostream>

class Doggos {
public:
    template <class T> int compare(const T&, const T&)
    {
        return 1;
    }


    template <typename It>
    auto fcn3(It beg, It end) -> decltype(*beg + 0)
    {
        end--;
        return *beg;
    }
};


int main()
{
    Doggos d;

    std::string s("fish");    
    
    std::cout << std::max<double>(30.132,20) << std::endl;

    d.compare(s, s);

    std::cout << (char)d.fcn3(s.begin(), s.end()) << std::endl;   

    return 0;
}
