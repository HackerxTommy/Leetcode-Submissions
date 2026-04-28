class Solution {
public:
    
    int solve(int i,int end, vector<int>&nums,vector<int>&dp){

       //base case
      if(i>end) return 0;

    //calculated check
    if(dp[i]!=-1) return dp[i];

    //condition check 
    //same logic like house robber 1 
    int rob = nums[i]+ solve(i+2,end,nums,dp);  //if rob current house then dont take adjacent and move to i+2 but always consider end due to circular array
    int skip= solve(i+1,end,nums,dp); // skip current house and consider end also
    return dp[i]= max(rob,skip);
   

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
         vector<int>dp1(n,-1),dp2(n,-1);
        if (n==1) return nums[0];
         //ismai circular array hai then we have to consider end because 
        //if i take 0 then 1 and n-1 are also adjacent 
        
        int case1= solve(0, n-2,nums, dp1); //so we take 0->n-2
        int case2= solve(1,n-1,nums,dp2); // 1, n-1
        return max(case1, case2);
        
    }
};