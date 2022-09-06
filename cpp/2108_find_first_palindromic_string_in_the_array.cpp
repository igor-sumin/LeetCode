#include <bits/stdc++.h>

using namespace std;

/***************************

Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.

***************************/

class Solution {
private:
    bool isPalindrome(const string& word) {
        int len = word.size();
        for (int i = 0; i < len / 2; i++) {
            if (word[i] != word[len - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    string firstPalindrome(vector<string>& words) {
        for (const auto& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        
        return "";
    }
};

int main() {
    cout << firstPalindrome({"abc","car","ada","racecar","cool"}) << endl;      // ada

    return 0;
}