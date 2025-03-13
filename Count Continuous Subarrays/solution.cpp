#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, m;
    vector<int> nums;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        nums.push_back(m);
    }
    
    long long result = 0;
    int left = 0;
    deque<int> minDeque, maxDeque;

    for (int right = 0; right < n; ++right) {
        // Maintain the minDeque
        while (!minDeque.empty() && nums[right] < nums[minDeque.back()]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);

        // Maintain the maxDeque
        while (!maxDeque.empty() && nums[right] > nums[maxDeque.back()]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        // Ensure the window is valid
        while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
            if (maxDeque.front() == left) maxDeque.pop_front();
            if (minDeque.front() == left) minDeque.pop_front();
            left++;
        }

        // Count the number of valid subarrays ending at `right`
        result += right - left + 1;
    }

    cout << result;
    
    return 0;
}
