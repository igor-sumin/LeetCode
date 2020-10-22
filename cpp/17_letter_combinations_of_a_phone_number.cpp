#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        
        vector<string> letters = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        
        vector<string> sett(1, "");
        for (char digit : digits) {
            
            vector<string> newSet;
            for (const string& prefix : sett) {
                // 'char' - 'char' = 'int'
                for (char letter : letters[digit - '2']) {
                    newSet.push_back(prefix + letter);
                }
            }
            
            newSet.swap(sett);
        }
        
        return sett;
    }
};

int main() {
    // Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
    // A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    return 0;
}