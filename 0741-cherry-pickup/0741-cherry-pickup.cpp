class Solution {
public:
    int n;

    int fun(int r1,int c1,int r2,int c2,vector<vector<int>>&grid,
            vector<vector<vector<vector<int>>>>&dp){

        if(r1>=n||c1>=n||r2>=n||c2>=n||grid[r1][c1]==-1||grid[r2][c2]==-1)
            return INT_MIN;

        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];

        if(dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];

        int cherry=0;

        if(r1==r2 && c1==c2)
            cherry+=grid[r1][c1];
        else
            cherry+=grid[r1][c1]+grid[r2][c2];

        int d1=fun(r1+1,c1,r2+1,c2,grid,dp);
        int d2=fun(r1,c1+1,r2,c2+1,grid,dp);
        int d3=fun(r1+1,c1,r2,c2+1,grid,dp);
        int d4=fun(r1,c1+1,r2+1,c2,grid,dp);

        int best = max({d1,d2,d3,d4});

        if(best == INT_MIN)
            return dp[r1][c1][r2][c2] = INT_MIN;

        cherry += best;

        return dp[r1][c1][r2][c2] = cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        n = grid.size();

        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(n,
            vector<vector<int>>(n,
            vector<int>(n,-1))));

        int ans = fun(0,0,0,0,grid,dp);

        return max(0,ans);
    }
};