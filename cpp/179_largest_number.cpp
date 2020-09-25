#include <bits/stdc++.h>

using namespace std;

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int i, int j) {
        return to_string(i) + to_string(j) > to_string(j) + to_string(i);
    });
    
    string result;
    for(auto& s : nums) {
        result += to_string(s);
    }
    
    return (result[0] == '0') ? "0" : result;
}

int main() {
    // Given a list of non negative integers, arrange them such that they form the largest number.
    // Input: [3,30,34,5,9]
    // Output: "9534330"
    
    cout << largestNumber({"3", "30", "34", "5", "9"}) << endl;

    return 0;
}