class Solution {
public:
    int n;
    int fun(int i, int target, vector<int>& nums, vector<vector<int>>& dp, int offset) {

    if (target < 0 || target >= dp[0].size()) return 0;

    if (i == n) {
        return target == offset;
    }

    if (dp[i][target] != -1) return dp[i][target];

    int plus = fun(i + 1, target + nums[i], nums, dp, offset);
    int minus = fun(i + 1, target - nums[i], nums, dp, offset);

    return dp[i][target] = plus + minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int totalsum = 0;
        for (int x : nums) totalsum += x;
        if (target > totalsum || target < -totalsum) return 0;
        
        vector<vector<int>> dp(n, vector<int>(2 * totalsum + 1, -1));

        return fun(0, target + totalsum, nums, dp, totalsum);
    }
};