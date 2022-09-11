#include <iostream>
#include <vector>

/*******************************************************

*******************************************************/

std::vector<int> runningSum(const std::vector<int>& in) {
    std::vector<int> out = in;
    for (int i = 1; i < in.size(); i++) {
        out[i] += out[i - 1];
    }

    return out;
}

int main() {
    runningSum({ 1, 2, 3, 4 });     // 1, 3, 6, 10

    return 0;
}
