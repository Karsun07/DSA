class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        int l=0,r=0;
        int size=0;

        while (r<n) {
            m[nums[r]]++;

            while (l<=r &&m[nums[r]] > k) {
                m[nums[l]]--;
                l++;
            }
            size = max(size, r-l+1);
            r++;
        }

        return size;
    }
};
