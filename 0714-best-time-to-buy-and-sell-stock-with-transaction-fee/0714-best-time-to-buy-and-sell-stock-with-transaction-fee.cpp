class Solution {
public:
    int n;
    int fun(int i,bool buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy){
            profit=max(-prices[i]+fun(i+1,false,prices,dp,fee),fun(i+1,true,prices,dp,fee));
        }
        if(!buy){
            profit=max(prices[i]-fee+fun(i+1,true,prices,dp,fee),fun(i+1,false,prices,dp,fee));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
      n=prices.size();
      vector<vector<int>>dp(n,vector<int>(2,-1));
      return fun(0,true,prices,dp,fee);
    }
};