#include <iostream>

using namespace std;

/*********

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside 
the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for 
those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

*********/

string vnytri(int& pos, const string& s) {
    int num = 0;
    string word;
    
    for (; pos < s.size(); pos++) {
        char let = s[pos];
        
        // num -> (3) * [ ... ]
        if (let >= '0' && let <= '9') {
            num = num * 10 + let - '0';
            
        // parser -> [ ... ]
        } else if (let == '[') {
            string subS = vnytri(++pos, s);
            
            for (; num > 0; num--) {
                word += subS;
            }
        
        // data return
        } else if (let == ']') {
            return word;
            
        // normal character
        } else {
            word += let;
        }
    }
    
    return word;        
}

string decodeString(const string& s) {
    int pos = 0;
    return vnytri(pos, s);
}


int main() {
	cout << decodeString("3[a]2[bc]") << endl;		// "aaabcbc"

	return 0;
}