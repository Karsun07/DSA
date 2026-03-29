class Solution {
public:
    int n;
    int lcs(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i>=n ||j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+lcs(i+1,j+1,s,t,dp);
        }
        return dp[i][j]=max(lcs(i+1,j,s,t,dp),lcs(i,j+1,s,t,dp));
    }
    int longestPalindromeSubseq(string s) {
         n=s.size();
        string t="";
        for(int i=n-1;i>=0;i--) t+=s[i];
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lcs(0,0,s,t,dp);
    }
};