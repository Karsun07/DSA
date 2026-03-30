class Solution {
public:
    int n1, n2;
    int minDistance(string word1, string word2) {
        n1 = word1.size();   
        n2 = word2.size();   

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return n1+n2-2*dp[0][0];

       
    }
};