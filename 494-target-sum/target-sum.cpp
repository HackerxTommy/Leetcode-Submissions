class Solution {
public:
 int solve(  int i, vector<int>&nums,int x,int target, vector<vector<int>>&dp){

     //base case 
     if(i== nums.size()){  // last mai pahouch gaya then x=0 return got the answer
        return (x==0);
       
     }
   
     
     //calculation check 
     if (dp[i][x]!=-1) return dp[i][x];

     //condition check
      int take =0;
      if (x>=nums[i]){
        take = solve(i+1, nums,x-nums[i], target, dp); // index badhega and sum update hoga 
      }
       int not_take =  solve(i+1, nums, x, target, dp); // index badhega sirf skip mai and sum utna hi rahega
        return dp[i][x]= take + not_take;
      
 }
 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();

        int sum= accumulate(nums.begin(),nums.end(),0);
        if (sum < abs(target)) return 0;
        if ((sum + target)%2!=0) return 0;
        int x= (sum+ target)/2; //cz p+n= sum and p-n= target then after adding them 2p=sum+target then p = (sum+target)/2

        vector<vector<int>>dp(n,vector<int>(x+1,-1)); 
        return  solve(0,nums,x,target,dp);

        
    }
};