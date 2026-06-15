class Solution {
public:

   int solve(int i,int j,int m, int n, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){

    //base case
    if (i>=m || j>=n) return 0; //outofbound
    if(i==m-1 && j==n-1) return 1; //reached destination
    if (obstacleGrid[i][j]==1) return 0; //obstacle check

    //calculated check
    if (dp[i][j]!=-1) return dp[i][j];

    //condition check recursive call move down and right
     return dp[i][j]= solve(i+1,j,m,n,obstacleGrid,dp)+ solve(i,j+1,m,n,obstacleGrid,dp);
   }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m= obstacleGrid.size(); //for rows
        int n= obstacleGrid[0].size(); //for columns

        // if shuru mai index 0 and index m-1& n-1 has obstacle means 1 then nothing happens chalega hi nahi
        if (obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,obstacleGrid,dp);
        
    }
};