#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

// Мое решение
int lastStoneWeight(vector<int>& stones) {
    
    auto pop_max = [&]() {
        int it = *stones.begin();
        stones.erase(stones.begin());
        return it;
    };
    
    while(stones.size() >= 2) {
        sort(stones.rbegin(), stones.rend());
        int x = pop_max();
        int y = pop_max();
        
        stones.push_back(x - y);
    }
    
    // for(auto s : stones) {
    //     cout << s << " ";
    // } cout << endl;
    
    if(stones.empty()) {
        return 0;
    }
    
    return stones.back();
}

// Гениальное решение
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> ans(stones.begin(), stones.end());
    
    while (ans.size() > 1) {
        int big = ans.top();
        ans.pop();
        int small = ans.top();
        ans.pop();
        
        if (big > small)
            ans.push(big - small);
    }
    
    if (ans.size())
        return ans.top();
    return 0;
}

int main() {
	vector<int> stones = {2, 7, 4, 1, 8, 1};
	cout << lastStoneWeight(stones) << endl;
	return 0;
}