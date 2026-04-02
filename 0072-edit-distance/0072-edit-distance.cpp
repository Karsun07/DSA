class Solution {
public:
    int n1,n2;
    int minDistance(string word1, string word2) {
        n1=word1.size(),n2=word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        // return fun(n1-1,n2-1,word1,word2,dp);
        for(int j=1;j<=n2;j++) dp[0][j]=j;
        for(int i=1;i<=n1;i++) dp[i][0]=i;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int ins=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int rep=1+dp[i-1][j-1];
                    dp[i][j]=min({ins,del,rep});
                }
            }
        }
        return dp[n1][n2];


    }
};