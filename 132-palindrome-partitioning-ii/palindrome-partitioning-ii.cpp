class Solution {
public:
    bool ispalindrome( int i, int j ,string &s, vector<vector<int>>& pal){ 
        // ye check karega palindrome substr hai ki nahi

        //base case
         if ( i>= j) return true; // single and empty subst always palindrome

         //calculated check
         if ( pal[i][j] != -1) return pal[i][j];

         //condition check 
         if ( s[i]== s[j]){
            return pal[i][j] = ispalindrome( i+1, j-1,s,pal);
            

         }
         else{
            return pal[i][j] =false;
         }

    }



int solve( int i, string &s, vector<int> &dp, vector<vector<int>> &pal){ // ye main hai partition manage  ke liye dp
        // base case
        int n= s.size();
        if ( i== n) return 0; // last mai pahuch gaya

        //calculated check 
        if ( dp[i] !=-1) return dp[i];
 
        //condition check 
        int ans = INT_MAX;
        for ( int j=i; j<n; j++){ // checking every substr
             if ( ispalindrome( i, j,s,pal)){
                ans = min( ans, 1+ solve(j+1, s,dp,pal));

             }

        }
        return dp[i]=ans;
    }



    int minCut(string s) {

        int n= s.size();
       // two dp banengi ek partition manage karegi palindrome substr ki and other palindrome substring hai ke nahi ye check karegi
       //  retunrn min cuts = partition -1;  1 cut means 2 partition

        
       vector<vector<int>> pal( n, vector<int>(n, -1)); // palindrome ke liye dp
       vector<int> dp(n,-1); // partition  manage ke liye  dp ye main hai

        
        
         return solve( 0, s, dp,pal) -1; // for cuts partition -1
        
    }
};