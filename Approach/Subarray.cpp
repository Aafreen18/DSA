//Subarray -> for integer
//Substrings -> for string
//CONTIGUOUS

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getAllSubarrays(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = i; j < n; ++j) {
            temp.push_back(nums[j]);
            result.push_back(temp);  // Add current subarray
        }
    }

    return result;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};
    vector<vector<int>> subarrays = getAllSubarrays(nums);

    cout << "All Subarrays:\n";
    for (const auto& sub : subarrays) {
        cout << "[";
        for (int i = 0; i < sub.size(); ++i) {
            cout << sub[i];
            if (i < sub.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
