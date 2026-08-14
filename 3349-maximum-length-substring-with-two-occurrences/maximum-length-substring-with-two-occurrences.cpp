class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n= s.size();
        unordered_map <char, int> mpp;
        int low =0, max_length =INT_MIN;
        for ( int  high =0; high<n; high++){
            mpp[s[high]]++;
        
        while( mpp[s[high]] >2){
            mpp[s[low]]--;
            low ++;
            
        }
        int length = high-low+1;
        max_length = max ( max_length, length);

        }
        return max_length;
        
    }
};