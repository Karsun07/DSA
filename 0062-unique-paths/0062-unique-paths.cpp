class Solution {
public:
    bool valid(int i, int j, int m, int n){
        return i < m && j < n;
    }

    int fun(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return 1;

        if(!valid(i, j, m, n)) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int d = fun(i+1, j, m, n, dp);
        int r = fun(i, j+1, m, n, dp);

        return dp[i][j] = d + r;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(0, 0, m, n, dp);
    }
};
