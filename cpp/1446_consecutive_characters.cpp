#include <iostream>

using namespace std;

/**********************

Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.


Example 1:
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

Example 3:
Input: s = "triplepillooooow"
Output: 5

Example 4:
Input: s = "hooraaaaaaaaaaay"
Output: 11

**********************/

int maxPower(const string& s) {
    int rep = 1;
    int res = 1;
    char c = s[0];
    
    for (int i = 1; i < s.size(); i++) {
        if (c == s[i]) {
            rep++;
        } else {
            res = max(res, rep);
            c = s[i];
            rep = 1;
        }
    }
    
    // max нужен для случая 'aaaaaa'
    return max(res, rep);
}

int main() {
	cout << maxPower('ayaaaala') << endl;	// 4

	return 0;
}