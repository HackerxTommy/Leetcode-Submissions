class Solution {
public:
     int solve(int n, vector<int>&coins, int amount, vector<int>&dp){
        //base case
        if (amount==0) return 0;
        if(amount <0 )return INT_MAX;
        //check if dp contains element
        if (dp[amount]!=-1) return dp[amount];

        //condition for calculating
       int ans= INT_MAX;
       for (int i=0;i<n;i++){
        int  rem= amount- coins[i];
        int  subs = solve(n,coins, rem, dp);
        if (subs!= INT_MAX){
            ans= min(ans,subs+1);
        }

       }


return dp[amount]=ans;
     }





    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int result= solve(n,coins,amount,dp);
       
         return (result == INT_MAX) ? -1 : result;
    }
};