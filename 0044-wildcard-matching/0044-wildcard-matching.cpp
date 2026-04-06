class Solution {
public:
    int ns, np;
    bool fun(int i, int j, string &s, string &p,vector<vector<int>>&dp) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) {
            while (j >= 0 && p[j] == '*') j--;
            return j < 0;
        }

        if (j < 0 && i >= 0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j]=fun(i - 1, j - 1, s, p,dp);
        }

        if (p[j] == '*') {
            bool ans=false;
            if (fun(i, j - 1, s, p,dp) || fun(i - 1, j, s, p,dp)) ans=true;

           
            return dp[i][j]=ans;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        ns = s.size();
        np = p.size();
        vector<vector<int>>dp(ns,vector<int>(np,-1));
        return fun(ns - 1, np - 1, s, p,dp);
    }
};