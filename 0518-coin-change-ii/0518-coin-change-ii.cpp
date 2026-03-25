class Solution {
public:
    int n;
    int fun(int i,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(amt==0) return 1;
        if(i==n-1){
            if(amt%coins[i]==0){
                return 1;
            }
            else return 0;
        }
        if(dp[i][amt]!=-1) return dp[i][amt];
        int nottake=fun(i+1,amt,coins,dp);
        int take=0;
        if(amt>=coins[i]){
            take=fun(i,amt-coins[i],coins,dp);
        }
        return dp[i][amt]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fun(0,amount,coins,dp);
    }
};