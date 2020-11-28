#include <iostream>

using namespace std;

/*****

Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

*****/

int strStr(const string& haystack, const string& needle) {
	if (needle.size() == 0)
		return 0;

	for (int i = 0; ; i++) {
		for (int j = 0; ; j++) {
			if (j == needle.size())
				return i;
			if (i + j == haystack.size())
				return -1;
			if (haystack[i + j] != needle[j]) 
				break;
		}
	}

	assert(false);
}

int main() {
	cout << strStr("hello", "ll") << endl;		// 2

	return 0;
}