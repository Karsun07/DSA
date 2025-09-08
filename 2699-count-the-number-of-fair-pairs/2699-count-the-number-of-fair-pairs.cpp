class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            int min_req = lower - nums[i], max_req = upper - nums[i];

            auto low  = lower_bound(nums.begin() + i + 1, nums.end(), min_req);
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), max_req);

            ans += (high - low);  
        }
        return ans;
    }
};
