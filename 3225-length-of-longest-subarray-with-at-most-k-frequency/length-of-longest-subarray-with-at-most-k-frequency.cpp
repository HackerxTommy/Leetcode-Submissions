class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
         int n=  nums.size();
         unordered_map<int, int> mpp;
         int low =0, max_length =INT_MIN;
         for ( int high =0; high <n; high++){
                mpp[nums[high]]++;
         
         while( mpp[nums[high]] >k){
            mpp[nums[low]]--;
            low++;
         }
         int len = high -low+1;
         max_length = max ( max_length, len);
         }
         return max_length;
         

    }
};