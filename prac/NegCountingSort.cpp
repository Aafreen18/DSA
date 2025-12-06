#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//It can sort both positive and negative numbers
int main() {
    vector<int> nums = {4, -2, 2, -8, 3, 3, -1};

    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());
    int range = maxVal - minVal + 1;

    vector<int> cntArr(range, 0);
    vector<int> output(nums.size());

    // Step 1: Count occurrences (using offset)
    for (int i = 0; i < nums.size(); i++) {
        cntArr[nums[i] - minVal]++;
    }

    // Step 2: Cumulative sum
    for (int i = 1; i < cntArr.size(); i++) {
        cntArr[i] += cntArr[i - 1];
    }

    // Step 3: Build output (backward for stability)
    for (int i = nums.size() - 1; i >= 0; i--) {
        output[cntArr[nums[i] - minVal] - 1] = nums[i];
        cntArr[nums[i] - minVal]--;
    }

    // Step 4: Print sorted output
    for (int x : output)
        cout << x << " ";
}
