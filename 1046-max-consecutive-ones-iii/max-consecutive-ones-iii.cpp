class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //sliding window pattern with fixed size for better and variable   size for optimal
       // maximum length nikalni hai while(zeroes count<k
       //variable size window
        
        int n=nums.size();
        int low=0,zerocount=0, maxlength=0;
        for(int high=0;high<n;high++){
            
            if (nums[high]==0) zerocount++;
           
             while(zerocount>k){
                //shrink jab tak zerocount<k
                if(nums[low]==0) zerocount--;
                  low++;
                  
             }
            maxlength= max(maxlength,(high-low+1));
            
        }
        return maxlength;
        
    }
};