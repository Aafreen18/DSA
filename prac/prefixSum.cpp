// Prefix sum = segment tree with no updates and only sum
// Segment tree = prefix sum + flexibility + updates

// Prefix Sum: fast queries, no updates
// Segment Tree: fast queries and fast updates

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//prefixSum[j] - prefixSum[i-1] = k
//prefixSum[i-1] = prefixSum[j] - k 
//need = prefixSum[j] - k

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        prefixSum[0] = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        unordered_map<int, int> m; // prefixSum -> count
        m[0] = 1;

        int totalCount = 0;5478

        for (int i = 0; i < n; i++)
        {
            int need = prefixSum[i] - k;// need = prefixSum[i-1]

            if (m.count(need))
            {
                totalCount += m[need];
            }

            m[prefixSum[i]]++;
        }

        return totalCount;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;

    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum equal to " << k << " is: " << result << endl;

    return 0;
}
