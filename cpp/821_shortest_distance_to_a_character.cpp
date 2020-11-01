#include <iostream>


using namespace std;

/****************
 
 *Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

 *Example 1:
 *Input: S = "loveleetcode", C = 'e'
 *Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

 ****************/

// 1. Относительное оптимальное решение
// Идем по строке два раза - слева направо, справа налево
// Отслеживаем расстояние до последней пройденной буквы С
// Обновляем min в массиве ответа

// l o v e l e e t c o d e
// - - - 0 1 0 0 1 2 3 4 0
// 3 2 1 0 1 0 0 4 3 2 1 0
// Ищем min:
// 3 2 1 0 1 0 0 1 2 2 1 0
vector<int> shortestToChar(const string& S, const char& C) {
    const int INF = S.size();
    vector<int> res(S.size(), INF);
    int dist = INF;
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == C) {
            dist = 0;
        } else {
            ++dist;
        }
        
        res[i] = dist;
    }
    
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == C) {
            dist = 0;
        } else {
            ++dist;
        }
        
        res[i] = min(res[i], dist);
    }
    
    return res;
}

// 2. Оптимальный способ
vector<int> shortestToChar(const string& S, const char& C) {
	int n = S.size();
	vector<int> res(n, 0);

	// 1. Заполнение до первого вхождения C
	int pos = n;
	for (int i = 0; i < n; i++) {
		if (S[i] == C) {
			pos = i;
			break;
		}
	}

	for (int i = 0; i < pos; i++) {
		res[i] = pos - i;
	}

	// 2. Заполнение промежутков между элементами C: ... C char char C ...
	for (int i = pos + 1; i < n; i++) {
		if (S[i] == C) {
			if (i > pos + 1) {
				pos = i;

				int i1 = pos + 1;
				int i2 = i - 1;
				int val = 1;

				while (true) {
					res[i1] = val;
					if (i1 == i2) {
						break;
					}
					i1++;

					res[i2] = val;
					if (i1 == i2) {
						break;
					}
					i2--;

					val++;
				}
			}

			pos = i;
		}
	}

	// 3. Заполняем после последнего вхождения элемента
	for (int i = pos + 1; i < n; i++) {
		res[i] = i - pos;
	}

	return res;
}

// 3. Подобие второго способа
vector<int> shortestToChar(const string& S, const char& C) {
	int n = S.size();
	vector<int> res(n, 0);

	// 1. Заполнение до первого вхождения C
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (S[i] == C) {
			pos = i;
			break;
		}
	}

	for (int i = 0; i < pos; i++) {
        res[i] = pos - i;
    }

	// 2. Заполнение промежутков между элементами C: ... C char char C ...
	for (int i = pos + 1; i < n; i++) {
		if (S[i] == C) {
			//  e  t c o d e
			// pos j - - - i
			for (int j = pos + 1; j < i; j++) {
				res[j] = min(j - pos, i - j);
			}

			pos = i;
		}
	}


	// 3. Заполняем после последнего вхождения элемента
	for (int i = pos + 1; i < n; i++) {
		res[i] = i - pos;
	}

	return res;
}


int main() {
	cout << shortestToChar("loveleetcode", "e") << endl;

	return 0;
}