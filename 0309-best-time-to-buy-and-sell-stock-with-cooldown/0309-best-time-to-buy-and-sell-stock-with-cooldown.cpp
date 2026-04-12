class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n=prices.size();  
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,0)));
 
         for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cooldown=1;cooldown>=0;cooldown--){
                    int profit;
                    if(cooldown){
                        profit=dp[i+1][1][0];
                    }
                    else if(buy){
                    profit=max(-prices[i]+dp[i+1][0][cooldown],dp[i+1][1][cooldown]);
                    }
                    else if(!buy){
                        profit=max(prices[i]+dp[i+1][1][1],dp[i+1][0][cooldown]);
                    }
                    dp[i][buy][cooldown]=profit;
                }

                }
            }
            return dp[0][1][0];

         }
        
    
};