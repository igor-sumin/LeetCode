#include <iostream>

using namespace std;

/*************
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. 
The richest customer is the customer that has the maximum wealth.

Example:
Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10

Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.

*************/

int maximumWealth(vector<vector<int>>& acc) {
    int res = 0;
    for (int i = 0; i < acc.size(); i++) {
        int temp = 0;
        for (int j = 0; j < acc[0].size(); j++) {
            temp += acc[i][j];
        }
        
        res = max(res, temp);
    }
    
    return res;
}

int main() {
    vector<vector<int>> accounts = {
        {1, 5},
        {7, 3},
        {3, 5}
    }

    cout << maximumWealth(accounts) << endl;        // 10

    return 0;
}
