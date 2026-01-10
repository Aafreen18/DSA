//Sliding window is a space-optimized alternative to prefix sum when the problem allows maintaining a running window instead of storing all prefix values.
//It is particularly useful for problems involving contiguous subarrays or substrings with certain properties.
//Sliding Window: space-optimized prefix sum for contiguous segments
//Prefix Sum: store all prefix sums for flexible queries

//no of subarrays with (sum = goal) = max len of subarray with (sum <= goal) - max len of subarray with (sum < goal)    ; not valid for frequency based problems

//for freqency based problems , use single function call of sliding window and maintain a map to store frequency of elements in the current window

#include <iostream>
#include <vector>
using namespace std;


int slidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, r = 0;
    int sum = 0;
    int maxLen = 0;

    while (r < n) {
        sum = sum + arr[r];        // expand window

        while (sum > k) {          // shrink window
            sum = sum - arr[l];
            l++;
        }

        if (sum <= k) {            // valid window
            maxLen = max(maxLen, r - l + 1);
        }

        r++;                        // move right
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, 7, 5};
    int k = 12;

    int result = slidingWindow(arr, k);
    cout << "Maximum length of subarray with sum <= " << k << " is: " << result << endl;

    return 0;
}