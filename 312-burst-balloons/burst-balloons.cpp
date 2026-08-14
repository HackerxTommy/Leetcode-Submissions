class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {

        // No balloon left in this interval
        if (i > j)
            return 0;

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        // Try every balloon k as the LAST balloon
        // to burst in interval [i...j]
        for (int k = i; k <= j; k++) {

            // Coins obtained if k is burst last:

            // Left interval  -> solve(i, k-1)
            // Right interval -> solve(k+1, j)

            // Since k is burst LAST, all balloons between
            // i and j except k are already removed.
            
            // Therefore immediate neighbours of k become:
            // nums[i-1] and nums[j+1]
        
            // Gain = nums[i-1] * nums[k] * nums[j+1]

            int coins = solve(i, k - 1, nums, dp) + nums[i - 1] * nums[k] * nums[j + 1] +
                        solve(k + 1, j, nums, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        // Add virtual balloons of value 1
        // [3,1,5,8]
        // becomes
        // [1,3,1,5,8,1]
        // every balloon always has a left and right neighbour.
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        // Original balloons are from index 1 to n
        return solve(1, n, nums, dp);
    }
};