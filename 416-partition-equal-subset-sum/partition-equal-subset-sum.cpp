class Solution {
public:

  bool solve(int i,int x, vector<int>&nums, vector<vector<int>>&dp){
    //base cases
        //base cases 
        if (x==0) return true; //mil gaya 
        if (i>=nums.size()) return false; //out of bound
    
    // calculated check
    if(dp[i][x]!=-1) return dp[i][x];

    //condition check
    bool take= false;
    if  (x>=nums[i]){
         take = solve(i+1,x-nums[i], nums,dp);
    }
    bool not_take= solve(i+1, x, nums,dp);

    return dp[i][x]=  take||not_take;
  }


    bool canPartition(vector<int>& nums) {
        
        int n= nums.size();
        // sabse pahle sum using accumulate fn
        int sum= accumulate(nums.begin(),nums.end(),0);
        if (sum%2!=0) {
            return false;  // 2X= sum
        }
        int x= sum/2;

        vector<vector<int>>dp(n+1, vector<int>(x+1,-1));//2d dp is liye bcz do variable change ho rahe hain x and i
       
        return solve(0,x,nums,dp);

    } 
    
};