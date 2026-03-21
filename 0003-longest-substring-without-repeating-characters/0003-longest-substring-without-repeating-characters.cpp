class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, maxlength = 0;
        unordered_map<char, int> mpp;

        for (int r = 0; r < n; r++) {
            mpp[s[r]]++;

         
            while (mpp[s[r]] > 1) { //checking  duplicate if freq >1 then shrink the window
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)  //agar freq 0 ho jaye to element ko hata do
                    mpp.erase(s[l]);
                l++;   // increase the left pointer
            }

            maxlength = max(maxlength, r - l + 1);
        }

        return maxlength;
    }
};