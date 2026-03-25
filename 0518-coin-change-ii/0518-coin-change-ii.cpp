class Solution {
public:
    int n;
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        for(int amt=0;amt<=amount;amt++){
            dp[n-1][amt]=amt%coins[n-1]==0?1:0;
        }
        for(int i=n-2;i>=0;i--){
            for(int amt=1;amt<=amount;amt++){
                long long nottake=dp[i+1][amt];
                long long take=0;
                if(amt>=coins[i]){
                   take=dp[i][amt-coins[i]];
                }
                dp[i][amt]=take+nottake;
            }
        }

        return dp[0][amount];
    }
};