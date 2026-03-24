class Solution {
public:
    int n;
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        if(n==1){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else{
                return -1;
            }
        }
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
      
        for(int amt=1;amt<=amount;amt++){
            if(amt%coins[n-1]==0){
                dp[n-1][amt]=amt/coins[n-1];
            }
            else dp[n-1][amt]=1e9;
        } 
        for(int i=n-2;i>=0;i--){
            for(int amt=1;amt<=amount;amt++){
                int nottake=dp[i+1][amt];
                int take=1e9;
                if(amt>=coins[i]){
                  take=1+dp[i][amt-coins[i]];
                }
                dp[i][amt]=min(take,nottake);
            }
        }
        





        int ans= dp[0][amount];
        return ans==1e9?-1:ans;
      

    }
};