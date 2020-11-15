#include <iostream>
#include <string>
#include <unordered_map> 

using namespace std;

/*********************************************

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3

Example 2:
Input: s = "IV"
Output: 4

Example 3:
Input: s = "IX"
Output: 9

Example 4:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

**********************************************/

int romanToInt(string s) {
    unordered_map<char, int> sym = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((i < s.size() - 1) && (sym[s[i]] < sym[s[i + 1]])) {
            res -= sym[s[i]];   
        } else {
            res += sym[s[i]];
        }
    }
    
    return res;
}


int main() {
	cout << romanToInt("MCMXCIV") << endl;		// 1994

	return 0;
}