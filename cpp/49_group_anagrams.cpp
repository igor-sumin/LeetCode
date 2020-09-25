#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> m;

    for(string s : strs) {
        string s2 = s;
        sort(s2.begin(), s2.end());
        m[s2].push_back(s);
    }

    vector<vector<string>> v;
    for(auto s : m) {
        v.push_back(s.second);
    }

    return v;

}

int main() {
    vector<string> anagrams = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(anagrams);
    for(auto s : res) {
        for(auto l : s) {
            cout << l << ", ";
        } cout << endl;
    }


    return 0;
}