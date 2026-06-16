class Solution {
public:
    // Helper function to find the length of the SCS using memoization
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // Base Cases: If one string is exhausted, the remaining length of the other string is needed
        if (i == 0) return j;
        if (j == 0) return i;

        // If already calculated, return the stored value
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, move diagonally (include character once)
        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
        } else {
            // If they don't match, take the minimum path between skipping in s1 vs skipping in s2
            return dp[i][j] = 1 + min(solve(i - 1, j, s1, s2, dp), 
                                      solve(i, j - 1, s1, s2, dp));
        }
    }

    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // dp[n+1][m+1] initialized to -1 to store lengths
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Step 1: Populate the DP table using top-down recursion
        solve(n, m, s1, s2, dp);

        // Step 2: Reconstruct the string using the populated DP table
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans.push_back(s1[i - 1]);
                i--;
                j--;
            } else {
                // Check which choice gave the minimum length during recursion
                // We map base case values safely if indices hit 0
                int opt1 = (i > 1) ? dp[i - 1][j] : j;
                int opt2 = (j > 1) ? dp[i][j - 1] : i;
                
                if (opt1 <= opt2) {
                    ans.push_back(s1[i - 1]);
                    i--;
                } else {
                    ans.push_back(s2[j - 1]);
                    j--;
                }
            }
        }

        // Collect remaining characters
        while (i > 0) {
            ans.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(s2[j - 1]);
            j--;
        }

        // Reverse the result since we built it backwards
        reverse(ans.begin(), ans.end());
        return ans;
    }
};