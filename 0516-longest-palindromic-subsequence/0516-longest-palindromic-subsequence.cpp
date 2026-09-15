class Solution {
public:
    int n;
    int fun(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int count=0;
        if(s[i]==s[j]){
            count=2+fun(i+1,j-1,s,dp);
        }
        else{
            count=max(fun(i+1,j,s,dp),fun(i,j-1,s,dp));
        }
        return dp[i][j]=count;
    }
    int longestPalindromeSubseq(string s) {
       n=s.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return fun(0,n-1,s,dp);


    }
};