class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]=-nums[i];
        }
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;

        long long ans = 0;

        while (i < j) {
            ans += 1LL * nums[j] * nums[j];
            ans -= 1LL * nums[i] * nums[i];

            i++;
            j--;
        }

        if (i == j) {
            ans += 1LL * nums[i] * nums[i];
        }

        return ans;
    }
};