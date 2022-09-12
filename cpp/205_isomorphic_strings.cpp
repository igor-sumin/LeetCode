#include <iostream>
#include <string>
#include <map>

/**********************

Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

**********************/

bool isIsomorphic(std::string a, std::string b) {
    std::map<char, char> amap;
    std::map<char, char> bmap;
    
    for (int i = 0; i < a.size(); i++) {
        if (amap.find(a[i]) == amap.end() && bmap.find(b[i]) == bmap.end()) {
            amap[a[i]] = b[i];
            bmap[b[i]] = a[i];
            
        } else if(!(amap[a[i]] == b[i] && bmap[b[i]] == a[i])) {
            return false;
        }
    }
                
    return true;
}

int main() {
    std::cout << isIsomorphic("egg", "add") << std::endl;    // true
    std::cout << isIsomorphic("geg", "dad") << std::endl;    // false

    return 0;
}