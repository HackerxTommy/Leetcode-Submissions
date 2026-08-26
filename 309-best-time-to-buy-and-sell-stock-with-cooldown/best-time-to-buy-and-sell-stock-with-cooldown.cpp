class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices, int n,
              vector<vector<int>>& dp) {

        //  base case

        if (idx >= n)
            return 0;

        // calculated check
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        
        // condition check

        if (buy == 1) {
            return dp[idx][buy] =
                       max(-prices[idx] + solve(idx + 1, 0, prices, n, dp), // buy stock

                           0 + solve(idx + 1, 1, prices, n, dp)); // not buy stock
        }

        return dp[idx][buy] =
                   max(prices[idx] + solve(idx + 2, 1, prices, n, dp), // sell stock ispe i +2 ho jayega due to 1 day cooldown , in cooldown period we donot buy stock next day
                       solve(idx + 1, 0, prices, n, dp));   // not sell stock
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 1, prices, n, dp);
    }
};