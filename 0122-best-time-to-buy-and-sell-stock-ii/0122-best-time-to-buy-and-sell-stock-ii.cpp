class Solution {
public:
    int n;
    int fun(int i,bool buy,vector<int>&prices,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy){
            profit=max(-prices[i]+fun(i+1,false,prices,dp),fun(i+1,true,prices,dp));
        }
        if(!buy){
            profit=max(prices[i]+fun(i+1,true,prices,dp),fun(i+1,false,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
      n=prices.size();
    //   buy-1(can buy=>but/notbuy) buy-0(cant buy=>sell/notsell)
      vector<vector<int>>dp(n,vector<int>(2,-1));
      return fun(0,true,prices,dp);
      
    }
};