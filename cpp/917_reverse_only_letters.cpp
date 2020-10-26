class Solution {
public:
    bool checkSym(const char& c) {
        // 1 способ
        int c1 = (int)c;
        if (c1 >= 65 && c1 <= 90 || c1 >= 97 && c1 <= 122) 
            return true;
        return false;

        // 2 способ - читабельнее
        return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
    }
    
    // 1 способ
    string reverseOnlyLetters(const string& S) {
        string result;
        auto it2 = S.rbegin();
        
        for (auto it1 = S.begin(); it1 != S.end(); ++it1) {
            if (checkSym(*it1)) {
                while (!checkSym(*it2)) {
                    ++it2;
                    assert(it2 != S.rend());
                }
            
                result += (*it2++);
            } else {
                result += (*it1);
            }
        }
        
        return result;
    }

    // 2 способ - читабельнее
    string reverseOnlyLetters(string& S) {
        int i = 0;
        int j = S.size() - 1;

        while (true) {
            while (i < j && !checkSym(S[i])) {
                i++;
            }
            while (i < j && !checkSym(S[j])) {
                j--;
            }

            if (i < j) {
                swap(S[i], S[j]);
                i++;
                j--;
            } else {
                break;
            }
        }

        return S;
    }
};

int main() {
    // Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

    // Example 1:
    // Input: "ab-cd"
    // Output: "dc-ba"

    // Example 2:
    // Input: "a-bC-dEf-ghIj"
    // Output: "j-Ih-gfE-dCba"

    // Example 3:
    // Input: "Test1ng-Leet=code-Q!"
    // Output: "Qedo1ct-eeLg=ntse-T!"

    return 0;
}