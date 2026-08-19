class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans(2,-1);

        auto first = lower_bound(nums.begin(), nums.end(), target);

        if(first == nums.end() || *first != target)
            return ans;

        ans[0] = first - nums.begin();

        auto last = upper_bound(nums.begin(), nums.end(), target);

        ans[1] = last - nums.begin() - 1;

        return ans;
    }
};