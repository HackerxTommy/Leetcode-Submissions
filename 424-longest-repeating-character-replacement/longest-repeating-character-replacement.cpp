class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int low=0,high=0, max_length=0, max_frequency=INT_MIN;
        unordered_map<char,int>mpp;
        while(high<n){
            mpp[s[high]]++; //current character ko map mai add karo
            max_frequency= max(max_frequency,mpp[s[high]]); // jo element sabse jyada bar aaya ho most frequent  usko update karo

            while ((high-low+1)-max_frequency>k){ //check if window is valid shrink the window if invalid
                mpp[s[low]]--;
                low++;
            }
           max_length= max(max_length,(high-low+1)); // update karo answer ko  har valid window pe
          high++;
        }
         return max_length;
    }
   
};