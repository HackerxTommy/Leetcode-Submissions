class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n= nums.size();
        int total_sum=0, max_sum=nums[0], min_sum= nums[0], curr_max=0, curr_min =0;
        for ( int i=0; i<n;i++ ){
            total_sum += nums[i];

            curr_max = max( nums[i], curr_max+ nums[i]);
            max_sum = max( max_sum, curr_max );

            curr_min= min( nums[i], curr_min+ nums[i]);
            min_sum = min( min_sum, curr_min );
        }
        if ( max_sum<0){
            return max_sum;
           
        }
         
         return max( max_sum, total_sum-min_sum);
            
        
    }
};