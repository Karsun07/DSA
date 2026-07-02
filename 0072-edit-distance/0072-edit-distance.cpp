class Solution {
public:
    int n1,n2;
    int fun(int i,int j,string &word1,string &word2,vector<vector<int>>&dp){
        if(i==n1){
            return n2-j;
        }
        if(j==n2){
            return n1-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=fun(i+1,j+1,word1,word2,dp);
        }
        int ins=1+fun(i,j+1,word1,word2,dp);
        int del=1+fun(i+1,j,word1,word2,dp);
        int rep=1+fun(i+1,j+1,word1,word2,dp);
        return dp[i][j]=min({ins,del,rep});
    }
    int minDistance(string word1, string word2) {
        n1=word1.size(),n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return fun(0,0,word1,word2,dp);


    }
};