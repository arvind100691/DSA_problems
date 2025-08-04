#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Initialize the map with Roman numeral values
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        
        // Iterate through the string
        for (int i = 0; i < s.length(); i++) {
            // If current value is less than next value, subtract current value
            // This handles cases like IV (4) and IX (9)
            if (i < s.length() - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            }
            // Otherwise, add the current value
            else {
                result += romanMap[s[i]];
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    vector<string> testCases = {"III", "LVIII", "MCMXCIV"};
    
    cout << "Roman to Integer Conversions:" << endl;
    cout << "----------------------------" << endl;
    
    for (const string& roman : testCases) {
        int result = solution.romanToInt(roman);
        cout << "\nTest Case:" << endl;
        cout << "Input: \"" << roman << "\"" << endl;
        cout << "Output: " << result << endl;
        cout << "Explanation: ";
        
        // Add specific explanations for test cases
        if (roman == "III") {
            cout << "III = 3" << endl;
            cout << "I = 1" << endl;
            cout << "III = 1 + 1 + 1 = 3" << endl;
        }
        else if (roman == "LVIII") {
            cout << "LVIII = 58" << endl;
            cout << "L = 50" << endl;
            cout << "V = 5" << endl;
            cout << "III = 3" << endl;
            cout << "LVIII = 50 + 5 + 3 = 58" << endl;
        }
        else if (roman == "MCMXCIV") {
            cout << "MCMXCIV = 1994" << endl;
            cout << "M = 1000" << endl;
            cout << "CM = 900 (1000-100)" << endl;
            cout << "XC = 90 (100-10)" << endl;
            cout << "IV = 4 (5-1)" << endl;
            cout << "MCMXCIV = 1000 + 900 + 90 + 4 = 1994" << endl;
        }
        cout << "----------------------------" << endl;
    }
    
    return 0;
}
