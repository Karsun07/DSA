class Solution {
public:
    int fun(int i,int n,vector<int>&dp,vector<int>&cost){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int x=fun(i+1,n,dp,cost);
        int y=fun(i+2,n,dp,cost);
        return dp[i]=min(x,y)+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        fun(0,n,dp,cost);
        return min(dp[0],dp[1]);


        
    }
};