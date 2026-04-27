class Solution {
public:
  int solve(string&s1,string&s2,int i, int j, vector<vector<int>>&dp){

    //base case
    if(i<0 ||j<0 ) return 0;

    //calculation check

    if(dp[i][j]!= -1) return dp[i][j];

    //condition check if both string are equal or not
    int take=0,skip=0;
    if(s1[i]==s2[j]){
        take= 1+ solve(s1,s2,i-1,j-1,dp); //dono ko le lenge
    }
    else{
        skip = max(solve(s1,s2,i-1,j,dp), solve(s1,s2,i,j-1,dp)); //ek ek karke lenge
    }

    return dp[i][j]=max(skip,take);
  }


    int longestPalindromeSubseq(string s1) {
       
        string s2=s1;
        //for palindrone reverse the string s1
        reverse(s2.begin(),s2.end());
        

         int n=s1.size()-1; //as 0->n-1

         int m=s2.size()-1; //as 0->m-1
vector<vector<int>>dp(n+1, vector<int>(m+1,-1)); //n+1 and m+1 isliye bcz dp ek aage chalta hai
        return solve(s1, s2,n,m,dp);
        
    }
};