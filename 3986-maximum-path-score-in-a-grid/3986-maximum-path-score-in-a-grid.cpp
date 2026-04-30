class Solution {
public:


int solve(int i,int j,int costused,int m,int n, vector<vector<int>>&grid,int k,vector<vector<vector<int>>>&dp){
    //base case
   if(i >= m || j >= n) return -1e9; ///out of band
    if (costused>k) return -1e9; //condition of cost of invalid path
    if (i==m-1 &&  j== n-1) return 0; //pahoch gaya

    //calculated check
    if(dp[i][j][costused]!=-1 ) return dp[i][j][costused];
    int ans= -1e9;
    
    //condition check
    //for down 
    if (i+1<m){
    int val= grid[i+1][j]; //row increase
    int addcost=(val==0? 0:1);  // for val 0 cost 0 otherwise 1
    

    ans= max(ans,val+ solve(i+1,j,addcost+costused,m,n,grid,k,dp));
    }
    // for right 
    if(j+1<n){
    int val= grid[i][j+1]; //column increase
   int addcost=(val==0? 0:1);

    ans= max(ans,val+ solve(i,j+1,addcost+costused,m,n,grid,k,dp));
    }

    return dp[i][j][costused]= ans;
}


    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        //3d dp due to m,n,cost 
  vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int finalans= solve(0,0,0,m,n,grid,k,dp);
        return (finalans < 0 ? -1 : finalans);
        
    }
};