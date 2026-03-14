class Solution {
public:
    int n;
    vector<vector<vector<int>>> memo;

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {

        int c2 = r1 + c1 - r2;

        if(r1>=n || c1>=n || r2>=n || c2>=n ||
           grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return -1e9;

        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];

        if(memo[r1][c1][r2] != -1)
            return memo[r1][c1][r2];

        int cherries = grid[r1][c1];

        if(r1!=r2)
            cherries += grid[r2][c2];

        int d1 = solve(grid,r1+1,c1,r2+1);
        int d2 = solve(grid,r1,c1+1,r2);
        int d3 = solve(grid,r1+1,c1,r2);
        int d4 = solve(grid,r1,c1+1,r2+1);

        int best = max({d1,d2,d3,d4});

        cherries += best;

        return memo[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        n = grid.size();

        memo = vector<vector<vector<int>>>(
            n, vector<vector<int>>(n, vector<int>(n,-1))
        );

        int ans = solve(grid,0,0,0);

        return max(0,ans);
    }
};