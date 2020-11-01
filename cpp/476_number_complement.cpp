#include <bits/stdc++.h>

using namespace std;

// 1 способ
int findComplement(int num) {
	vector<int> bits;
	while(num) {
		bits.push_back(num % 2);
		num /= 2;
	}

	reverse(bits.begin(), bits.end());

	int result = 0;
	for(int i = bits.size() - 1; i >= 0; i--) {
		if(bits[i] == 0) {
			result += pow(2, bits.size() - 1 - i)
		}
	}

	return result;
}

// 2 способ
int findComplement(int num) {
	// int -> 32 bits
	bitset<32> bits(num);

	int res = 0;
	for (int i = 0; i < 31; i++) {
		if (bits[i] == 0) {
			res += pow(2, i);
		} else {
			bits[i] = bits[i] ^ 1;

			if (bits == 0) {
				break;
			}
		}
	}

	return res;
}


int main() {
	// Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

	// Input: 5
	// Output: 2
	// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2

	cout << findComplement(5) << endl;

	return 0;
}