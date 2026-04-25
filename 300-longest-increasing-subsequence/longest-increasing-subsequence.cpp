class Solution {
public:
int solve(int i, int prev, vector<vector<int>>&dp, vector<int>&nums){ //using dp without using temp array
  //base case
  if(i == nums.size()) return 0;

  //calculated check
  if (dp[i][prev+1]!=-1) return dp[i][prev+1]; //prev+1 isliye kyoki prev ki value -1->n-1 ho sakti hai and dp mai index not -ve

  //condition check

   int skip = solve(i+1, prev, dp, nums);  //nahi liya then i->i+1  & prev as it is

   int take=0;
   if( prev ==-1 || nums[i]>nums[prev]){   //condition ki prev -1 pe hai  or  nums[i]> nums[prev]
    take = 1+ solve(i+1, i, dp, nums);     // i->i+1 due to take, and prev->i 
   }
     return dp[i][prev+1]= max(skip, take);


}



    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // do index lenge i=0 and prev jo ki -1

        return solve(0,-1,dp,nums);
        
    }
};