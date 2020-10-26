class Solution {
public:
    bool checkSym(const char& c) {
        // В этой задаче учитываются еще и цифры (what!?)
        // аналогом данной функции является - std::isalnum
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
    
    bool isPalindrome(string& s) {
        int ln = s.size();
        int i = 0;
        int j = ln - 1;
        
        while (i < j) {
            while (i < j && !checkSym(s[i])) {
                i++;
            }
            while (i < j && !checkSym(s[j])) {
                j--;
            }
            
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } 
            
            i++;
            j--;
        }
        
        return true;
    }
};

int main() {
    // Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
    // Note: For the purpose of this problem, we define empty string as valid palindrome.

    // Example 1:
    // Input: "A man, a plan, a canal: Panama"
    // Output: true

    // Example 2:
    // Input: "race a car"
    // Output: false

    return 0;
}