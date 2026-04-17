class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
           
            if(i>res) return false;
            res = max(i + nums[i], res);
            
        }

       return true;
    }
};