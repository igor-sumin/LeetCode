bool isPowerOfTwo(int n) {
    // 1 способ - наивный 
    if(n < 0) {
        return false;
    }
    uint64_t two = 1;
    while(two != n && two < uint64_t(n)) {
        two *= 2;
    }
    
    return two == n;
    
    // 2 способ
    // Степень двойки - это один единичный бит в двоичной записи числа
    
    // После вычитания 1 из числа последний бит 1 превратится в 0, 
    // а все биты 0 после него превратятся в 1
    // 42:00101010
    // 41:  00101001
    
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    // Given an integer n, write a function to determine if it is a power of two.

    // Input: n = 16
    // Output: true
    // Explanation: 2^4 = 16

    cout << isPowerOfTwo(5) << endl;    // false
}
