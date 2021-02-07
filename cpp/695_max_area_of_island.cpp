#include <iostream>
#include <vector>

/****************

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[
[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]
]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.

****************/

using matr = std::vector<std::vector<int>>;

int dfs(matr& matrix, int i, int j) {
    if (i < 0 || j < 0 || \
        i >= matrix.size() || j >= matrix[0].size() || \
        matrix[i][j] == 0
    ) return 0;

    matrix[i][j] = 0;
    return 1 + dfs(matrix, i + 1, j) + \
               dfs(matrix, i, j + 1) + \
               dfs(matrix, i - 1, j) + \
               dfs(matrix, i, j - 1);
}

int maxAreaOfIsland(matr& matrix) {
    int max_ = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 1) {
                max_ = max(max_, dfs(matrix, i, j));
            }
        }
    }

    return max_;
}

int main(int argc, char** argv) {

    return 0;
}

