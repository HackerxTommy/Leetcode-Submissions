class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += (num % 2); //even numbers

            if (mpp.find(sum - k) != mpp.end()) { //odd (sum-k)  
                count += mpp[sum - k]; //count freq of odd
            }

            mpp[sum]++;
        }

        return count;
    }
};