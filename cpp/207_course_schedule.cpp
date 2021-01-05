#include <iostream>
#include <vector>

using namespace std;

/*******************************************************

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

*******************************************************/

// Статусы курсов
enum class State {
    NOT_VISITED,
    VISITING,
    VISITED
};

bool hasLoop(int vertex, vector<State>& state, const vector<vector<int>>& dependency) {
    // нашли цикл - зашли в вершину, котроую сейчас обходим
    // \
    //  \
    //   * - вновь пришли в эту вершину
    //  / \
    // *   *
    //  \ /
    //   *
    if (state[vertex] == State::VISITING) {
        return true;
    }
    
    // уже обходили элементы от этой вершины
    if (state[vertex] == State::VISITED) {
        return false;
    }
    
    assert(state[vertex] == State::NOT_VISITED);
    state[vertex] = State::VISITING;

    for (const int& dep_course : dependency[vertex]) {
        if (hasLoop(dep_course, state, dependency)) {
            return true;
        }
    }
    
    state[vertex] = State::VISITED;
    // циклов из вершины vertex нет
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Нахождение ориентированного цикла в графе
    // 3 цвета вершин:
    // - не посещалась
    // - сейчас посещается
    // - уже посещена
    
    // Список зависимостей каждого курса
    vector<vector<int>> dependency(numCourses);
    for (const auto course : prerequisites) {
        dependency[course[0]].push_back(course[1]);
    }
    
    // Состояние курсов
    vector<State> state(numCourses, State::NOT_VISITED);
    
    // идем по вершинам
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == State::NOT_VISITED) {
            // невозмонжо завершить - зациклились
            if (hasLoop(i, state, dependency)) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    vector<vector<int>> prerequisites = {
        {1, 0},
        {0, 1}
    };

    cout << findOrder(2, prerequisites) << endl;    // false

    return 0;
}