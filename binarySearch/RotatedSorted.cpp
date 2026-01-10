//Time complexity = o(log n)
#include <vector>           // for std::vector
#include <unordered_map>    // for std::unordered_map
#include <list>             // for std::list
#include <set>              // for std::set
#include <climits>          // for INT_MAX
#include <utility>          // for std::pair, std::make_pair
#include <algorithm>  
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int piv = s+(e-s)/2;

            if(nums[piv] == target){
                return piv;
            }
            
            if(nums[s] <= nums[piv]){
                int l = s;
                int r = piv;
                while (l <= r) {
                    int m = (l + r) / 2;

                    if (nums[m] == target)
                        return m;
                    else if (nums[m] < target)
                        l = m + 1;
                    else
                        r = m - 1;
                }

                s = piv + 1; 
            }
            else{
                int l = piv;
                int r = e;
                while (l <= r) {
                    int m = (l + r) / 2;

                    if (nums[m] == target)
                        return m;
                    else if (nums[m] < target)
                        l = m + 1;
                    else
                        r = m - 1;
                }
                e = piv - 1;
            }
                    
        }
    
        return -1; 
    }
};