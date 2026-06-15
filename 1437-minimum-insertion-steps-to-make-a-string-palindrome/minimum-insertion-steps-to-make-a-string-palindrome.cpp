class Solution {
public:
    int solve(int i, int j, string &s, string &s1,vector<vector<int>>&dp){
        //base case
        if (i<0 || j<0) return 0; 
         //calculated check
         if (dp[i][j]!=-1) return dp[i][j];
         //condition check
         int take =0, skip=0;
         if(s[i]==s1[j]){
            take = 1+ solve(i-1,j-1,s,s1,dp);
         }
         else{
            skip= max(solve(i-1,j,s,s1,dp),solve(i,j-1,s,s1,dp));
         }
         return dp[i][j]= max(skip,take);
    } 
 
   int lps(string s){
    string s1=s;
    reverse (s1.begin(),s1.end());
    int m= s.size()-1;
    int n=s1.size()-1;
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return solve(m,n,s,s1,dp);

    
   }

    int minInsertions(string s) {
        int k= s.size();
        
        int o= lps(s);
        return k-o;
        
        
    }
};