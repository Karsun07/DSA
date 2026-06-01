class Solution {
public:
    int n;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans = 0;
            int maxi = 0;
            for (int j = i; j < min(n, i + k); j++) {
                maxi = max(maxi, arr[j]);
                int len = j - i + 1;
                ans = max(ans,maxi * len + dp[j + 1]);
            }

            dp[i]=ans;
        }
        return dp[0];
    }
};