#include <iostream>
#include <string>
#include <map>
using namespace std;
int romanToInt(std::string s) {
    // Create a map to store the values of each Roman numeral
    std::map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    // Initialize the result as 0
    int result = 0;

    // Iterate through the string, starting from the end
    for (int i = s.length() - 1; i >= 0; i--) {
        // Get the value of the current Roman numeral
        int val = values[s[i]];

        // Check if the current Roman numeral has been repeated more than three times
        if (i > 0 && s[i] == s[i - 1] && s[i] == s[i - 2] && s[i] == s[i - 3]) {
            // Return -1 if the Roman numeral has been repeated more than three times
            std::cout << "invalid roman letter";
            exit(0);
        }

        // If the current value is greater than or equal to the next value, add it to the result
        // Otherwise, subtract it from the result
        if (i == s.length() - 1 || val >= values[s[i + 1]]) {
            result += val;
        } else {
            result -= val;
        }
    }

    return result;
}


int main(){
    int value = romanToInt("XXXX");
    
    std::cout << value;

    return 0;
}