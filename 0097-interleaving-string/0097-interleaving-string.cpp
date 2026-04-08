class Solution {
public:
    int n1,n2,n3;
    bool fun(int i,int j,string &s1,string &s2,string &s3,vector<vector<int>>&dp){
        int k=i+j;
        if(i==n1 && j==n2 && k==n3) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool res=false;
        if(i<n1 && s1[i]==s3[k]){
            if(fun(i+1,j,s1,s2,s3,dp)) res=true;
        }
        if(j<n2 &&  s2[j]==s3[k]){
            if(fun(i,j+1,s1,s2,s3,dp)) res=true;
        }
        return dp[i][j]=res;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return fun(0,0,s1,s2,s3,dp);

    }
};