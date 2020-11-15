#include <iostream>
#include <string>

using namespace std;

/*****************************************************************************************
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701

*****************************************************************************************/

int titleToNumber(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res * 26 + (s[i] - 'A' + 1);
    }
    
    return res;
}


int main() {
	cout << titleToNumber("ZY") << endl; 	// 701

	return 0;
}