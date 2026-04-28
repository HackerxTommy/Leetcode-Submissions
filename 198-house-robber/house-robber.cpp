class Solution {
public:
     int dp[1001];
    int solve(int i, vector<int>&nums){
       //base case
    if(i>=nums.size()) return 0;
    //calculated check
    if(dp[i]!=-1)  return dp[i];
    //condition check 
    //we cannot rob adjacent houses
    //so we have two choice first rob current  house nums[i] and go to i+2 adjacent
    //second skip current house and goto i+1 ,take max of both
    return dp[i]= max((nums[i]+solve(i+2,nums)), solve(i+1,nums)); //take(rob) current house and skip current house

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
        
    }
};