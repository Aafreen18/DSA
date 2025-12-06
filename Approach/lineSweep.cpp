#include <vector>  
#include<set>
#include<math.h> 
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> nums;
        int n = buildings.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            nums.push_back({buildings[i][0], -buildings[i][2]});
            nums.push_back({buildings[i][1], buildings[i][2]});
        }

        sort(nums.begin(), nums.end());

        multiset<int> s;
        s.insert(0);
        int prev = 0;
        int curr;

        for(int i=0; i<nums.size(); i++){
            if(nums[i][1] < 0){
                s.insert(-nums[i][1]);
            }
            else{
               s.erase(s.find(nums[i][1]));
            }

            curr = *s.rbegin();
            
            if(prev != curr){
                ans.push_back({nums[i][0], curr});
                prev = curr;  
            }
           
        }

        return ans;
    }

};