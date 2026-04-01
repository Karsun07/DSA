class Solution {
public:
    int n, m;
    long long dp[1001][1001];
    int rec(string &s, string &t, int i, int j){
        if(j==m){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long ans = 0;
        if(s[i]==t[j]){
            ans+=rec(s, t, i+1, j+1);
        }
        ans+=rec(s, t, i+1, j);
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        n = s.size(), m = t.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = -1;
            }
        }
        return rec(s, t, 0, 0);
    }
};