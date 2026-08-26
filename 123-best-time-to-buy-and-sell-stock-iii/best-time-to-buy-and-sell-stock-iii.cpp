class Solution {
public:

    int solve(int idx, int buy, int cap,vector<int>& prices, int n,vector<vector<vector<int>>>& dp) {

        // base case
        if(idx == n || cap == 0) // max 2 hi transaction ho sakte hain buy and sell, b and s
            return 0;
 
         // calculated check
        if(dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];

        // condition check
        if(buy == 1) {

            // Buy
            int buyStock =
                -prices[idx] + solve(idx + 1, 0, cap, prices, n, dp);

            // Don't buy
            int notBuy =
                solve(idx + 1, 1, cap, prices, n, dp);

            return dp[idx][buy][cap] = max(buyStock, notBuy);
        }

        // Sell
        int sell =
            prices[idx] + solve(idx + 1, 1, cap - 1, prices, n, dp);

        // Don't sell
        int notSell =
            solve(idx + 1, 0, cap, prices, n, dp);

        return dp[idx][buy][cap] = max(sell, notSell);
    
}

    int maxProfit(vector<int>& prices){
        int n = prices.size();

       // maximum number of transactions is k , cap means 1 transaction buy and sell

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3 + 1, -1))); //3d dp due to index, buy/sell, no of transaction

        return solve(0, 1, 2, prices, n, dp);
    }
};