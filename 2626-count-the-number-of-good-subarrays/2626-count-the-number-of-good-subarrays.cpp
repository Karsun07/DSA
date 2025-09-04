class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        long long pairs = 0, ans = 0;
        int n = nums.size();
        int left = 0;

        for (int right = 0; right < n; right++) {
            pairs += map[nums[right]];
            map[nums[right]]++;

            while (pairs >= k) {
                ans += (n - right);//array start at left and ending at right+1....n also should counted
                map[nums[left]]--;
                pairs -= map[nums[left]];
                left++;
            }
        }
        return ans;
    }
};
