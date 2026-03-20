class Solution {
public:
    int n;
    bool fun(int i,int target, vector<int>& nums,vector<vector<int>>&dp) {
        if(target == 0){
            return 1;
        }
        if(i >= n || target < 0){
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        bool take=fun(i+1, target-nums[i],nums,dp);
        bool notTake=fun(i+1, target,nums,dp);
        return dp[i][target]=(take||notTake);   
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return 0;
        int target = sum / 2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return fun(0,target,nums,dp);
    }
};