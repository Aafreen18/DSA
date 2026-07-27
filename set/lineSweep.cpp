#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        // Stores all events (start and end of every building)
        // Format:
        // {x, -height} -> building starts
        // {x, +height} -> building ends
        vector<vector<int>> nums;

        int n = buildings.size();

        // Final skyline points
        vector<vector<int>> ans;

        // -----------------------------------------------------
        // Step 1: Convert every building into two events
        // -----------------------------------------------------
        // Building = [left, right, height]
        //
        // Example:
        // [2,9,10]
        //
        // becomes
        // (2,-10)  -> start
        // (9,10)   -> end
        //
        // Why negative?
        // Because after sorting:
        // start events come before end events at same x.
        //
        for(int i = 0; i < n; i++) {
            nums.push_back({buildings[i][0], -buildings[i][2]});
            nums.push_back({buildings[i][1],  buildings[i][2]});
        }

        // Sort by x-coordinate.
        // If x is same:
        // negative height comes first
        // (start before end)
        sort(nums.begin(), nums.end());

        // -----------------------------------------------------
        // Multiset stores heights of all ACTIVE buildings.
        //
        // Why multiset?
        // Because many buildings can have same height.
        // It automatically keeps them sorted.
        //
        // Example:
        // {10,15,15,20}
        //
        // Largest height = *s.rbegin()
        // -----------------------------------------------------
        multiset<int> s;

        // Ground level is always active.
        s.insert(0);

        // Previous maximum height
        int prev = 0;

        // Current maximum height
        int curr;

        // -----------------------------------------------------
        // Process every event from left to right
        // -----------------------------------------------------
        for(int i = 0; i < nums.size(); i++) {

            // --------------------------
            // Start of a building
            // --------------------------
            if(nums[i][1] < 0) {

                // Add its height
                s.insert(-nums[i][1]);
            }

            // --------------------------
            // End of a building
            // --------------------------
            else {

                // Remove ONE occurrence
                s.erase(s.find(nums[i][1]));
            }

            // Current tallest building
            curr = *s.rbegin();

            // If tallest height changed,
            // skyline changes.
            if(prev != curr) {

                ans.push_back({nums[i][0], curr});

                prev = curr;
            }
        }

        return ans;
    }
};
