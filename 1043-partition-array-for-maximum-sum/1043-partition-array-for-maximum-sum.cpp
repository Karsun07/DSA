class Solution {
public:
    int n;
    int fun(int i, int k, vector<int>& arr,vector<int>&dp) {
        if (i == n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        int maxi = 0;
        for (int j = i; j < min(n, i + k); j++) {
            maxi = max(maxi, arr[j]);
            int len = j - i + 1;
            ans = max(ans,maxi * len + fun(j + 1, k, arr,dp));
        }

        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int>dp(n,-1);
        return fun(0, k, arr,dp);
    }
};