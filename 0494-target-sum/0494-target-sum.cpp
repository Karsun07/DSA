class Solution {
public:
    int n;

    int fun(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) {
            return target == 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

     
        if (nums[i] == 0) {
            return dp[i][target] = 2 * fun(i + 1, target, nums, dp);
        }

        int take = 0;
        if (target >= nums[i]) {
            take = fun(i + 1, target - nums[i], nums, dp);
        }

        int nottake = fun(i + 1, target, nums, dp);

        return dp[i][target] = take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int totalsum = 0;
        for (int x : nums) totalsum += x;

       
        if ((totalsum - target) < 0 || (totalsum - target) % 2 != 0)
            return 0;

        target = (totalsum - target) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return fun(0, target, nums, dp);
    }
};