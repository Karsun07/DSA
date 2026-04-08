class Solution {
public:
    int n1,n2,n3;
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
  
        dp[n1][n2] = 1;
        for(int i = n1; i>=0; i--){
            for(int j= n2;j>=0;j--){
                int k=i+j;
                 if (i == n1 && j == n2) continue;
                 dp[i][j]=0;
                if(i<n1 && s1[i]==s3[k]){
                    dp[i][j]|=dp[i+1][j];
                }
                if(j<n2 && s2[j]==s3[k]){
                    dp[i][j]|=dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};