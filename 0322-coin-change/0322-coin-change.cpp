class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int amt = 1; amt <= amount; amt++) {
            dp[n][amt] = 1e9;
        }
        dp[n][0] = 0;

        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[n - 1] == 0)
                dp[n - 1][amt] = amt / coins[n - 1];
            else
                dp[n - 1][amt] = 1e9;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int amt = 0; amt <= amount; amt++) {

                int nottake = dp[i + 1][amt];

                int take = 1e9;
                if (amt >= coins[i]) {
                    take = 1 + dp[i][amt - coins[i]];
                }

                dp[i][amt] = min(take, nottake);
            }
        }

        int ans = dp[0][amount];
        return (ans >= 1e9 ? -1 : ans);
    }
};