class Solution {
public:
    int fun(int i, vector<int>& arr,vector<int>&dp) {
        if (i >= arr.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        int take = arr[i] + fun(i + 2, arr,dp);
        int notTake = fun(i + 1, arr,dp);

        return dp[i]=max(take, notTake);
    }

    int rob(vector<int>& nums) {

        if (nums.size() == 1)
            return nums[0];

        vector<int> temp1;
        vector<int> temp2;
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        for (int i = 1; i < nums.size(); i++)
            temp1.push_back(nums[i]);

        for (int i = 0; i < nums.size() - 1; i++)
            temp2.push_back(nums[i]);

        return max(fun(0, temp1,dp1), fun(0, temp2,dp2));
    }
};