#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*******************************

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower", "flow", "flight"]
Output: "fl"

Example 2:
Input: strs = ["dog", "racecar", "car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*******************************/

// 1 способ - (Runtime: 4 ms, Memory Usage: 9.4 MB)
string longestCommonPrefix1(const vector<string>& strs) {
	if (strs.empty()) 
		return "";

	string pref;
	for (int j = 0; j < strs[0].size(); j++) {
		for (int i = 1; i < strs.size(); i++) {
			if ((j >= strs[i].size()) || (strs[0][j] != strs[i][j])) {
				return pref;
			}
		}

		pref += strs[0][j];
	}

	return pref;
}

// 2 способ - (Runtime: 4 ms, Memory Usage: 9.6 MB)
string longestCommonPrefix2(vector<string>& strs) {
	if (strs.empty()) 
		return "";

	int ln = strs.size();
	sort(strs.begin(), strs.end());
	
	string wordfirst = strs[0];
	string wordlast = strs[ln - 1];
	int mn = min(wordfirst.size(), wordlast.size());

	int i = 0;
	for (; i < mn; i++) {
		if (wordfirst[i] != wordlast[i])
			break;
	}

	return wordfirst.substr(0, i);
}

// 3 способ - (Runtime: 4 ms, Memory Usage: 9.7 MB)
string matching(const string& prev, const string& cur) {
	int mn = min(prev.size(), cur.size());
	int i = 0;
	for (; i < mn; i++) {
		if (prev[i] != cur[i])
			break;
	}

	return prev.substr(0, i);
}

string longestCommonPrefix3(vector<string>& strs) {
	if (strs.empty()) 
		return "";

	string pref = strs[0];
	for (int i = 1; i < strs.size(); i++) {
		pref = matching(pref, strs[i]);
	}

	return pref;
}

int main() {
	vector<string> strs = {"flower", "flow", "flight"};
	cout << longestCommonPrefix1(strs) << endl;

	return 0;
}