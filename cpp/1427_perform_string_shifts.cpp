#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <chrono>
#include <sys/time.h>

#include <iostream>
using namespace std;

// Мое решение
string stringShift(string s, vector<vector<int>>& shift) {
	// 1. Идем пока матрица не будет нулевой
    // 2. Вызываем i раз функции
    
    int size_str = s.size();
    int n = shift.size();
    
    auto pop_max = [&](int direction) {
        // Сдвиг влево на 1 означает удаление первого символа s и добавление его в конец.
        if(direction == 0) {
            auto c = *s.begin();
            s.erase(s.begin());
            s += c;
        } 
        // Cдвиг вправо на 1 означает удаление последнего символа s и добавление его в начало.
        else {
            auto c = s.end();
            char k = *(--c);
            s.erase(c);
            s = k + s;
        }
    };
    
    for(int i = 0; i < n; i++) {
        int l = shift[i][1];

        if(l >= size_str) {
        	l -= size_str;
        }

        while(l) {
            pop_max(shift[i][0]);
            l--;
        }
    }
    
    return s;
}

// Гениальное решение
string stringShift(string s, vector<vector<int>>& shift) {
    int total = 0;
    for(vector<int> pp : shift) {
        if(pp[0] == 0) {
            total -= pp[1];
        } else {
            total += pp[1];
        }
    }

    total %= s.size();
    if(total < 0) {
        total += s.size();
    }

    // Метод string.substr()
    // Возвращает подстроку [pos, pos+count). 
    // Если запрашиваемая подстрока выходит за границы конца строки или если count == npos, 
    // диапазон возвращаемой подстроки будет [pos, size()).
    return s.substr(s.size() - total) + s.substr(0, s.size() - total);
}

int main() {
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
	string s = "abc";
	vector<vector<int>> shift = {
		{0,1}, {1,5}, {1, 2}
	};

	cout << stringShift(s, shift) << endl;
	gettimeofday(&tv2, NULL);
	printf("Time taken in execution = %f seconds\n",
	      (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
	      (double) (tv2.tv_sec - tv1.tv_sec));
	
	// Output:
	// abc
	// Time taken in execution = 0.000998 seconds

	return 0;
}