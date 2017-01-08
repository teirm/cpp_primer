/* Display Ex
 * Purpose: Display Exercise
 * for exercises since I am lazy
 */
#ifndef DISPLAY_EX_GUARD
#define DISPLAY_EX_GUARD

#include <iostream>
#include <string>

void display_ex(const std::string exercise)
{
    std::string underscore(exercise.size(), '-'); 
    
    std::cout << "\n" << exercise << "\n" <<
        underscore << std::endl;
}

#endif
