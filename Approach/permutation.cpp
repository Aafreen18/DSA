#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {          
        vector<vector<int>> ans;                
          
        recur(0, ans, nums);         
        return ans;                             
    }

    void recur(int idx, vector<vector<int>>& ans, vector<int>& nums) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            recur(idx+1, ans, nums); 
            swap(nums[idx], nums[i]);
        }
    }
};
