class Solution {
public:
    int n;
    int fun(int i, string &s,vector<int>&dp) {
        if (i == n) return 1;
        
        if (s[i] == '0') return 0;
        if(dp[i]!=-1) return dp[i];

         int count = fun(i + 1, s,dp); 

        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
            count += fun(i + 2, s,dp); 
        }

        return dp[i]=count;
    }

    int numDecodings(string s) {
        n = s.size();
        vector<int>dp(n,-1);
        return fun(0, s,dp);
    }
};