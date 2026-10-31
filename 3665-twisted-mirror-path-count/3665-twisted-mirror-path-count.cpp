class Solution {
public:
    int n, m;
    const int MOD=1e9+7;

    int fun(int i, int j, bool rmov, vector<vector<int>>& grid,vector<vector<vector<int>>>&dp) {
        if(i >= n || j >= m)
            return 0;

        if(i == n-1 && j == m-1)
            return 1;
        if(dp[i][j][rmov]!=-1) return dp[i][j][rmov];
        int d = 0, r = 0;

        if(grid[i][j] == 0) {
            d = fun(i+1, j, 0, grid,dp);
            r = fun(i, j+1, 1, grid,dp);
        }
        else {

            if(rmov == 1) {
                d = fun(i+1, j, 0, grid,dp);
            }
            else {
                r = fun(i, j+1, 1, grid,dp);
            }
        }

        return dp[i][j][rmov]=(d + r) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return fun(0, 0, 0, grid,dp);
    }
};