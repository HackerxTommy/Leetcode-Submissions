class Solution {
public:

  int solve(int i,int j,int m, int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //base case
     if (i == m - 1 && j == n - 1) return grid[i][j]; // means reached end
     if (i>=m || j>=n ) return 1e9; //outofbound
     //calculated check 
     if (dp[i][j]!=-1) return dp[i][j];
     //condition check 
     //for down
     int down = grid[i][j] + solve(i+1,j,m,n,grid,dp);
     //for  right 
     int right =  grid[i][j]+ solve(i,j+1,m,n,grid,dp);
    
      return dp[i][j] = min(down,right);
  }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,grid,dp);
        
    }
};