class Solution {
public:
    int atleast(vector<int>& nums, int k, int n) {
        int l = 0, r = 0, distinct = 0, total = 0;
        unordered_map<int,int> freq;
        
        while (r < n) {
            if (freq[nums[r]] == 0) distinct++;
            freq[nums[r]]++;
            
            while (distinct == k) {
                total += (n - r);  
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) distinct--;
                l++;
            }
            r++;
        }
        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return atleast(nums, k, n) - atleast(nums, k+1, n);
    }
};
