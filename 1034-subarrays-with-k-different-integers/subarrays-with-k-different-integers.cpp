class Solution {

public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, count = 0;
        unordered_map<int,int> mpp;

        for (int high = 0; high < n; high++) {
            mpp[nums[high]]++;

            while (mpp.size() > k) { 
                mpp[nums[low]]--;
                if (mpp[nums[low]] == 0) {
                    mpp.erase(nums[low]);
                }
                low++;
            }

            count += (high - low + 1); ///store
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
   