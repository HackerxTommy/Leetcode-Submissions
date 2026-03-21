class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, maxlength = 0;
        unordered_map<char, int> mpp;

        for (int r = 0; r < n; r++) {
            mpp[s[r]]++;

         
            while (mpp[s[r]] > 1) { //checking  duplicate
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) 
                    mpp.erase(s[l]);
                l++;  
            }

            maxlength = max(maxlength, r - l + 1);
        }

        return maxlength;
    }
};