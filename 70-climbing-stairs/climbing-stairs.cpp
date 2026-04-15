class Solution {
public:
    int climbStairs(int n) { //Tabulation approach bottom-up
    //in tabulation we go from base cases to main problem

        if(n<=1) return n; //if stair is 0 and stair is 1 then return 0&1 means n
       vector<int>dp(n+1,-1); //initialise the dp of size n+1 with elements -1
       //base cases
       dp[0]=1;      
       dp[1]=1;
       
       for(int i=2;i<=n;i++){
       dp[i]= dp[i-1]+dp[i-2];  //recursive relation
       }
      return dp[n];
    }
 
};