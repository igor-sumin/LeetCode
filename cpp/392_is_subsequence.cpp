#include <iostream>
#include <string>

/**********************

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string 
by deleting some (can be none) of the characters without disturbing the relative positions of 
the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

**********************/

bool isSubsequence(std::string s, std::string t) {
    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        if (s[j] == t[i]) {
            j++;
        }
    }
    
    return j == s.size();
}

int main() {
    std::cout << isSubsequence("abc", "ahbgdc") << std::endl;    // true
    std::cout << isSubsequence("axc", "ahbgdc") << std::endl;    // false

    return 0;
}