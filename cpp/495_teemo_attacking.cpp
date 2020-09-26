#include <bits/stdc++.h>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty())
        return 0;
    
    int result = 0;
    for (int i = 0; i < timeSeries.size() - 1; i++) {
        int interval = timeSeries[i + 1] - timeSeries[i];
        
        if (duration <= interval) {
            result += duration;
        } else {
            result += interval;
        }
    }
    
    // add poisoning at the end 
    return result + duration;
}

int main() {
    // // Description
    // In LOL world, there is a hero called Teemo and his attacking can make his enemy Ashe be in poisoned condition. 
    // Now, given the Teemo's attacking ascending time series towards Ashe and the poisoning time duration per Teemo's attacking, 
    // you need to output the total time that Ashe is in poisoned condition.

    // You may assume that Teemo attacks at the very beginning of a specific time point, and makes Ashe be in poisoned condition immediately.

    // // Example
    // Input: [1,4], 2
    // Output: 4
    // Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately. 
    // This poisoned status will last 2 seconds until the end of time point 2. 
    // And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds. 
    // So you finally need to output 4.

    cout << findPoisonedDuration({1, 4}, 2) << endl;

    return 0;
}