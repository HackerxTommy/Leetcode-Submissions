class Solution {
public:
    // Helper function to check if s[i...j] is a palindrome
    bool isPalindrome(int i, int j, string& s, vector<vector<int>>& dp) {
        // Base cases
        if (i >= j) return true; // Single characters or empty strings are palindromes
        
        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];
        
        // Recursive step
        if (s[i] == s[j]) {
            return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
        }
        
        return dp[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        // dp table initialized to -1
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Generate all possible substrings and check them
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(i, j, s, dp)) {
                    count++;
                }
            }
        }
        return count;
    }
};