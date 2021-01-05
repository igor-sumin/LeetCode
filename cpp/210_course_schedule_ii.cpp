#include <iostream>
#include <vector>

using namespace std;

/*******************************************************

There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, 
if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. 
To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

*******************************************************/

// Статусы курсов
enum struct State {
    NOT_VISITED,
    VISITING,
    VISITED
};

bool hasCycle(
    int course, const vector<vector<int>>& depends, \
    vector<State>& state, vector<int>& res
) {
    if (state[course] == State::VISITED) {
        return false;
    }
    // нашли цикл
    if (state[course] == State::VISITING) {
        return true;
    }
    assert(state[course] == State::NOT_VISITED);
    
    // пометили курс как посещаемый - вход в рекурсию
    state[course] = State::VISITING;
    for (int depCourse : depends[course]) {
        // рекурсивно нашли ориентированный цикл
        if (hasCycle(depCourse, depends, state, res)) {
            return true;
        }
    }
    
    // пометили курс как посещенный - в нем нет циклов
    state[course] = State::VISITED;
    res.push_back(course);
    
    // нет никаких зависимостей
    return false;
}

// O(nums + p) по времени и по памяти
vector<int> findOrder(int nums, const vector<vector<int>>& p) {
    // Нахождение ориентированного цикла в графе
    // 3 цвета вершин:
    // - не посещалась
    // - сейчас посещается
    // - уже посещена
    
    vector<int> res;
    
    // Список зависимостей каждого курса
    vector<vector<int>> depends(nums);
    
    for (const auto &pair : p) {
        depends[pair[0]].push_back(pair[1]);
    }
    
    // Состояние курсов
    vector<State> state(nums, State::NOT_VISITED);
    for (int course = 0; course < nums; course++) {
        if (hasCycle(course, depends, state, res)) {
            return {};
        }
    }
            
    return res;
}

int main() {
	vector<vector<int>> prerequisites = {
		{1, 0},
		{2, 0},
		{3, 1},
		{3, 2}
	};

	vector<int> res = findOrder(2, prerequisites);

	for (const int& r : res) {
		cout << r << " ";		// {0, 2, 1, 3}
	} cout << endl;

	return 0;
}