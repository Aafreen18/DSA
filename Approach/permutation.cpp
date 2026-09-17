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



                              [1, 2, 3]
                             idx = 0
                                │
              ┌─────────────────┼─────────────────┐
              │                 │                 │
           i = 0             i = 1             i = 2
              │                 │                 │
         swap(0,0)         swap(1,0)         swap(2,0)
              │                 │                 │
              ▼                 ▼                 ▼
          [1, 2, 3]         [2, 1, 3]         [3, 2, 1]
          idx = 1            idx = 1            idx = 1
              │                 │                 │
        ┌─────┴─────┐     ┌─────┴─────┐     ┌─────┴─────┐
        │           │     │           │     │           │
      i = 1       i = 2 i = 1       i = 2 i = 1       i = 2
        │           │     │           │     │           │
   swap(1,1)    swap(2,1) swap(1,1) swap(2,1) swap(1,1) swap(2,1)
        │           │     │           │     │           │
        ▼           ▼     ▼           ▼     ▼           ▼
    [1, 2, 3]   [1, 3, 2] [2, 1, 3] [2, 3, 1] [3, 2, 1] [3, 1, 2]
     idx = 2     idx = 2   idx = 2   idx = 2   idx = 2   idx = 2
        │           │         │         │         │         │
        ▼           ▼         ▼         ▼         ▼         ▼
     recur(2)    recur(2)  recur(2)  recur(2)  recur(2)  recur(2)
        │           │         │         │         │         │
        ▼           ▼         ▼         ▼         ▼         ▼
    swap(2,2)   swap(2,2) swap(2,2) swap(2,2) swap(2,2) swap(2,2)
        │           │         │         │         │         │
        ▼           ▼         ▼         ▼         ▼         ▼
    [1,2,3]     [1,3,2]   [2,1,3]   [2,3,1]   [3,2,1]   [3,1,2]
     idx=3       idx=3     idx=3      idx=3     idx=3      idx=3
        │           │         │         │         │         │
        ▼           ▼         ▼         ▼         ▼         ▼
       SAVE        SAVE      SAVE      SAVE      SAVE      SAVE
        │           │         │         │         │         │
        ▼           ▼         ▼         ▼         ▼         ▼
      123          132       213       231       321       312
