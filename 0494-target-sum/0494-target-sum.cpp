class Solution {
public:
    int n;

    int fun(int i, int sum, vector<int>& nums, int target) {
        if (i == n)
            return sum == target;

        return fun(i + 1, sum + nums[i], nums, target) +
               fun(i + 1, sum - nums[i], nums, target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return fun(0, 0, nums, target);
    }
};