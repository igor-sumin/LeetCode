#include <iostream>
#include <vector>

using namespace std;

/*************

Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*************/

vector<int> spiralOrder(const vector<vector<int>>& a) {
    if (a.empty() || a[0].empty())
        return {};
    
    int m = a.size();
    int n = a[0].size();
    vector<int> res(m * n);
    
    int pos = 0;
    int row_begin = 0;
    int row_end = m - 1;
    int col_begin = 0;
    int col_end = n - 1;
    
    while (row_begin <= row_end && col_begin <= col_end) {
        // идем вправо
        for (int j = col_begin; j <= col_end; j++)
            res[pos++] = a[row_begin][j];
        row_begin++;
            
        // идем вниз
        for (int i = row_begin; i <= row_end; i++)
            res[pos++] = a[i][col_end];
        col_end--;
            
        if (row_begin <= row_end)
            // идем влево
            for (int j = col_end; j >= col_begin; j--)
                res[pos++] = a[row_end][j];
        row_end--;
            
        if (col_begin <= col_end)
            // идем вверх
            for (int i = row_end; i >= row_begin; i--)
                res[pos++] = a[i][col_begin];
        col_begin++;
    }
    
    return res;
}

int main() {
	vector<vector<int>> a = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	cout << spiralOrder(a) << endl;		// {1,2,3,6,9,8,7,4,5}

	return 0;
}