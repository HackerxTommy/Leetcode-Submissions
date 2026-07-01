class Solution {
public:
   int helper(int i, int j, string &s, string &t, vector<vector<int>>&dp, int n, int m ){

   //base case
   if (j == m) return 1; //t string puri mil chuki hai
   if( i == n) return 0; //means s string exhaust ho chuki hai and hume t puri nahi mili
    
    //calculated check
    if (dp[i][j]!=-1) return dp[i][j];

//condition check
    
    if(s[i]==t[j]){ //if characters match 
     int take = helper(i+1,j+1,s,t,dp,n,m);  // take both character and move in both s and t indices
      int skip = helper (i+1, j, s,t,dp,n,m); // skip this character and only move in s 
      return dp[i][j] = take + skip; // store result in dp table
 }
    else{ // if characters donot match
    return dp[i][j] = helper(i+1,j,s,t,dp,n,m); // only move in s if characters donot match
 }
    }

   int numDistinct(string s, string t) {
        int n= s.size();
        int m = t.size();
        
        vector<vector<int>>dp(n, vector<int>(m,-1));
        
        return helper(0,0,s,t,dp,n,m);
       
    }
};