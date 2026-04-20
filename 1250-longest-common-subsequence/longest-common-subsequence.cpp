class Solution {
public:
//topdown(memo+recursion)
    int dp[1005][1005];

    int solve(string &a , string &b, int i, int j){
       //base case
       if(i<0 ||  j<0) return 0;

        //check if already calculated 
         if(dp[i][j]!=-1 ) return dp[i][j];

         //condition compare both strings
        int take=0,skip=0;
         if (a[i]==b[j]){
             take= 1+solve(a,b,i-1,j-1); //dono ko lelo
         }
          else{
             skip = max(solve(a,b,i-1,j),solve(a,b,i,j-1)); //alternate lelo 1,1 karke

          }
         return dp[i][j] = max(take, skip);

    }

    int longestCommonSubsequence(string a, string b) {
        int n=a.size()-1;
        int m=b.size()-1;
        memset(dp, -1, sizeof(dp));
         return solve( a, b,n,m);

        
    }
};