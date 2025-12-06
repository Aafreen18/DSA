//subsets == subsequence
//NOT CONTINGUOUS

#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    // Exclude nums[index]
    generateSubsets(nums, index + 1, current, result);

    // Include nums[index]
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);
    current.pop_back();  // backtrack
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> current;

    generateSubsets(nums, 0, current, result);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num;
        }
        cout << "]\n";
    }

    return 0;
}
