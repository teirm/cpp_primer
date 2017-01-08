/* Exercise 3.1 from CPP Primer
 * Purpose: Use `using` to redo some
 * exercises
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void sum_numbers()
{

    int sum = 0;
    int value = 50;
    
    while (value <= 100) {
        sum += value;
        value++;
    }

    cout << "The sum from 50 to 100 is: " << 
        sum << endl;
}

void countdown()
{
    int start = 10;

    while (start >= 0) {
        cout << "Value is: " << start-- <<
            endl;
    }
}

void range_display()
{
    int start_range = 0;
    int end_range = 0;

    cout << "Please enter two numbers: " << endl;
    cin >> start_range >> end_range;
    
    while (start_range <= end_range) {
        cout << "Value: " << start_range++ << endl; 
    }
}

int main() 
{
    cout << "Exercise 1.9\n-------------" << endl; 
    sum_numbers();

    cout << "\nExercise 1.10\n-------------" << endl;
    countdown();

    cout << "\nExercise 1.11\n-------------" << endl;
    range_display();
}
