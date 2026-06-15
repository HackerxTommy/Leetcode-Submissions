class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &maxLength) {
        // Base Case: If either string is exhausted, the match length is 0
        if (i == 0 || j == 0) return 0;
        
        // If already calculated, return the cached continuous streak length
        if (dp[i][j] != -1) return dp[i][j];
        
        // Always explore choices to traverse the entire string matrix
        // (Even if they don't match here, a match might exist further down)
        // ye check karega left and right mai match
        solve(i - 1, j, s1, s2, dp, maxLength);
        solve(i, j - 1, s1, s2, dp, maxLength);
        
        // If characters match, extend the continuous streak from the previous characters
        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp, maxLength);
            maxLength = max(maxLength, dp[i][j]); // Update our global maximum
            return dp[i][j];
        }
        
        // As you rightly said: if they don't match, the substring streak breaks -> reset to 0
        return dp[i][j] = 0;
    }
    
    int longCommSubstr(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        
        // dp[i][j] will store the longest common suffix of s1[0...i-1] and s2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        int maxLength = 0; // Tracks the global maximum substring length found
        solve(m, n, s1, s2, dp, maxLength);
        
        return maxLength;
    }
};