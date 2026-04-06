class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int low = 0, count = 0;
        unordered_map<char,int> mpp;

        for (int high = 0; high < n; high++) {
            mpp[s[high]]++;

            while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                count += (n - high);
                mpp[s[low]]--;
                low++;
            }
        }

        return count;
    }
};