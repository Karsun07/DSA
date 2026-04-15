class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int curr=1;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(nums[curr]>nums[prev]){
                    dp[curr]=max(dp[curr],dp[prev]+1);
                }
            }
            maxi=max(maxi,dp[curr]);
        }
        return maxi;
    }
};