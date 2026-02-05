class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes=0;
        int l=0;
        int ans=0;
        int n=nums.size();
        for(int r=0;r<n;r++){
            if(nums[r]==0) zeroes++;
            while(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=k) ans=max(ans,r-l+1);
        }
        return ans;

    }
};