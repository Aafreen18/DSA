#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        // Create combined string
        string combined = s + "#" + rev;

        // Compute LPS array using the algorithm you shared
        vector<int> lps = computeLPS(combined);

        // Longest palindromic prefix length
        int longestPrefix = lps.back();

        // The remaining suffix needs to be reversed and added in front
        string suffix = s.substr(longestPrefix);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }

private:
    vector<int> computeLPS(string pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);

        int length = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};
