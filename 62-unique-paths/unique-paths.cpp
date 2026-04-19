class Solution {
public:
      int solve(int i, int j, int m, int n, vector<vector<int>>&dp){
        //base case 
        if (i>=m || j>=n) return 0; //outof bounds
        if (i == m-1 && j == n-1) return dp[i][j] =1; // reached end pahuch gaya
        //pahle se calculate hua hai to usko return kardo
        if(dp[i][j]!=-1) return dp[i][j];
// ab conditions lagao means operations like down to (i+1,j )row and right to (i,j+1) column

return dp[i][j]=solve(i+1,j,m,n,dp)+ solve(i,j+1,m,n,dp);

      }




    int uniquePaths(int m, int n) { //2d dp due to two operations
        vector<vector<int>>dp(m, vector<int>(n,-1)); //2d dp m rows,n colums with -1 inside
        return solve(0,0,m,n,dp);
    }
};