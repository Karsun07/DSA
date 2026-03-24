class Solution {
public:
    int n;
    int fun(int i,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(target==0) return 0;
        if(i==n-1){
            if(target%coins[i]==0){
                return target/coins[i];
            }
            else return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int nottake=fun(i+1,target,coins,dp);
        int take=INT_MAX;
        if(target>=coins[i]){
            take=1+fun(i,target-coins[i],coins,dp);
        }
        return dp[i][target]=min(take,nottake);
    }
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
        int ans= fun(0,amount,coins,dp);
        return ans==1e9?-1:ans;
      

    }
};