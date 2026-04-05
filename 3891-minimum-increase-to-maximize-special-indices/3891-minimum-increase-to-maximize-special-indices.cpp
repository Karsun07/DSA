#define ll long long
class Solution {
public:
    int n;

    ll fun(int i, int skip, vector<int>& nums, vector<vector<ll>>& dp) {
        if (i >= n - 1) return 0;

        if (dp[i][skip] != -1) return dp[i][skip];

        ll cost = max(0, max(nums[i - 1], nums[i + 1]) - nums[i] + 1);

        if (skip == 1) {
            return dp[i][skip] = cost + fun(i + 2, 1, nums, dp);
        } else {
            ll take_skip = cost + fun(i + 3, 1, nums, dp);
            ll no_skip = cost + fun(i + 2, 0, nums, dp);
            return dp[i][skip] = min(no_skip, take_skip);
        }
    }

    long long minIncrease(vector<int>& nums) {
        n = nums.size();

        if (n % 2) {
            ll cost = 0;
            for (int i = 1; i < n - 1; i += 2) {
                cost += max(0LL, (ll)max(nums[i - 1], nums[i + 1]) - nums[i] + 1);
            }
            return cost;
        }

        vector<vector<ll>> dp(n, vector<ll>(2, -1));

        return min(fun(1, 0, nums, dp), fun(2, 1, nums, dp));
    }
};