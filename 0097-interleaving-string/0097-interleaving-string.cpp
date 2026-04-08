class Solution {
public:
    int n1,n2,n3;
    bool fun(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp){
        if(i==n1 && j==n2 && k==n3) return true;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool res=false;
        if(i<n1 && s1[i]==s3[k]){
            if(fun(i+1,j,k+1,s1,s2,s3,dp)) res=true;
        }
        if(j<n2 &&  s2[j]==s3[k]){
            if(fun(i,j+1,k+1,s1,s2,s3,dp)) res=true;
        }
        return dp[i][j][k]=res;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
        return fun(0,0,0,s1,s2,s3,dp);

    }
};