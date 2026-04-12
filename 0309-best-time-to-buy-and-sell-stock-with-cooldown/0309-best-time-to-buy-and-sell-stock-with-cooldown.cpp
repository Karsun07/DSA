class Solution {
public:
    int n;
    int fun(int i,bool buy,bool cooldown,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i==n) return 0;
        if(dp[i][buy][cooldown]!=-1) return dp[i][buy][cooldown];
        int profit;
        if(cooldown){
            profit=fun(i+1,1,0,prices,dp);
        }
        else if(buy){
            profit=max(-prices[i]+fun(i+1,false,cooldown,prices,dp),fun(i+1,true,cooldown,prices,dp));
        }
        else if(!buy){
            profit=max(prices[i]+fun(i+1,true,true,prices,dp),fun(i+1,false,cooldown,prices,dp));
        }
        return dp[i][buy][cooldown]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();  
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
      return fun(0,true,0,prices,dp);
    }
};