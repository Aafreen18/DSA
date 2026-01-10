#include <vector>           
using namespace std;

//floydCycle detection algorithm detects cycle in a linked list and also finds the starting point of the cycle.
//Here we are using this algorithm to find the duplicate number in an array where numbers are in the range 1 to n and array size is n+1.
//The duplicate number will create a cycle in the linked list representation of the array.
//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle (intersection point)
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        

        // Phase 2: Find entrance to cycle (duplicate number)
        //fast is still at intersection point
        // we are only moving slow to the start of the array
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
