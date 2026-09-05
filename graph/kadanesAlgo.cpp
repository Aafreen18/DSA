#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum); 

            if(currSum < 0){
                currSum=0;;
            }
        }

        return maxSum;
    }

    int minSubarraySum(vector<int> &arr) {
        int currSum = arr[0];
        int minSum = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            currSum = min(arr[i], currSum + arr[i]);
            
            minSum = min(minSum, currSum);
        }
        
        return minSum;
    }

};
