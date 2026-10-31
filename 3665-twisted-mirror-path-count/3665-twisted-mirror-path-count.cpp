class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(2, 0))
        );

        // Destination
        dp[n-1][m-1][0] = 1;
        dp[n-1][m-1][1] = 1;

        for(int i = n-1; i >= 0; i--) {

            for(int j = m-1; j >= 0; j--) {

                if(i == n-1 && j == m-1)
                    continue;

                // rmov = 1
                // We entered this cell while moving RIGHT
                if(grid[i][j] == 1) {

                    // Mirror reflects RIGHT -> DOWN
                    if(i+1 < n)
                        dp[i][j][1] = dp[i+1][j][0];

                }
                else {

                    // Empty cell: can move DOWN or RIGHT
                    if(i+1 < n)
                        dp[i][j][1] += dp[i+1][j][0];

                    if(j+1 < m)
                        dp[i][j][1] += dp[i][j+1][1];

                    dp[i][j][1] %= MOD;
                }

                // rmov = 0
                // We entered this cell while moving DOWN
                if(grid[i][j] == 1) {

                    // Mirror reflects DOWN -> RIGHT
                    if(j+1 < m)
                        dp[i][j][0] = dp[i][j+1][1];

                }
                else {

                    // Empty cell: can move DOWN or RIGHT
                    if(i+1 < n)
                        dp[i][j][0] += dp[i+1][j][0];

                    if(j+1 < m)
                        dp[i][j][0] += dp[i][j+1][1];

                    dp[i][j][0] %= MOD;
                }
            }
        }

    
        return dp[0][0][0] ;
    }
};