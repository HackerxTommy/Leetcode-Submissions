class Solution {
public:
   
    int isPalindrome(int i, int j, string &s, vector<vector<int>> &dp) {
        // Base case: empty or 1-char substring
        if (i >= j) return 1;

        // Return memoized result if available
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive check
        if (s[i] == s[j]) {
            return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
        }

        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int start = 0;
        int maxLength = 1;

        // Test every starting and ending index
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s, dp)) {
                    int len = j - i + 1;
                    if (len > maxLength) {
                        maxLength = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};