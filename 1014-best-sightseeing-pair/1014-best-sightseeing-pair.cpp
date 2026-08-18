class Solution {
public:
    int fun(int i,int size,vector<int>&values,vector<vector<int>>&dp){
        if(i==values.size() && size!=2 ){
            return INT_MIN;
        }
        if(size==2){
            return 0;
        }
        if(dp[i][size]!=-1) return dp[i][size];

        int take=INT_MIN;
        if(size==0){
            take=i+values[i]+fun(i+1,size+1,values,dp);
        }
        else if(size==1){
            take=-i+values[i]+fun(i+1,size+1,values,dp);
        }
        
        int nottake=fun(i+1,size,values,dp);
        
        return dp[i][size]=max(take,nottake);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(3,INT_MIN));

        for(int i=0;i<=n;i++) dp[i][2]=0;

        for(int i=n-1;i>=0;i--){
            for(int size=1;size>=0;size--){
                int take=INT_MIN;
                if(size==0){
                    take=i+values[i]+dp[i+1][size+1];
                }
                else if(size==1){
                    take=-i+values[i]+dp[i+1][size+1];
                }
        
                int nottake=dp[i+1][size];
        
                dp[i][size]=max(take,nottake);

            }
        }
        return dp[0][0];
        
    }
};