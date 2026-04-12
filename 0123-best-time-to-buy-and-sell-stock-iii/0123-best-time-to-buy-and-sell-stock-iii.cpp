class Solution {
public:
    int n;
    int fun(int i,bool buy,int trans,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i==n || trans==2) return 0;
        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
        int profit;
        if(buy){
            profit=max(-prices[i]+fun(i+1,false,trans,prices,dp),fun(i+1,true,trans,prices,dp));
        }
        if(!buy){
            profit=max(prices[i]+fun(i+1,true,trans+1,prices,dp),fun(i+1,false,trans,prices,dp));
        }
        return dp[i][buy][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
      n=prices.size();
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
      return fun(0,true,0,prices,dp);
    }
};