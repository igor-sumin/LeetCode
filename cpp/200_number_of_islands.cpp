#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <iostream>
using namespace std;

// Гениальное решение
void CheckIn(vector<vector<char>>& grid, int i, int j) {
	// Проверка индексов и воды
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
		return;
	}

	// Маркируем посещенный участок
	grid[i][j] = '0';

	// Смотрим соседние участки
	CheckIn(grid, i + 1, j);
    CheckIn(grid, i - 1, j);
    CheckIn(grid, i, j + 1);
    CheckIn(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
	int isl = 0;
	// int n = длина строки * длину столбца
	// int n = grid[0].size() * grid.size();

	if(grid.size() == 0) {
		return isl;
	}

	// Внутренняя матрица
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[0].size(); j++) {
			// Если суша
			if(grid[i][j] == '1') {
				CheckIn(grid, i, j);
				isl++;
			}
		}
	}

	return isl;
}

int main() {
	// 1 - суша
	// 0 - вода
	vector<vector<char>> field = {
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'}
	};

	cout << numIslands(field) << endl;

	return 0;
}