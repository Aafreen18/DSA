// Top - Down Approach = Recursion + Memoization
// Bottom - Up Approach = Tabulation Method

//When to apply: 1)Overlapping 2)Subproblems

//top-bottom
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1); // initialize dp array with -1
        return recurFib(n, dp);
    }

    int recurFib(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        dp[n] = recurFib(n - 1, dp) + recurFib(n - 2, dp);

        return dp[n];
    }
};

//bottom to top
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};


//space optimization
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};
