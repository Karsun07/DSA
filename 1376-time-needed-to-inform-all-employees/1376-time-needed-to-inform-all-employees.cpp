class Solution {
public:

    vector<vector<int>> adj;
    vector<int> dp;

    int dfs(int man, vector<int>& informTime) {

        if (adj[man].empty())
            return 0;

        if (dp[man] != -1)
            return dp[man];

        int mx = 0;

        for (int emp : adj[man]) {
            mx = max(mx, dfs(emp, informTime));
        }

        return dp[man] = mx + informTime[man];
    }

    int numOfMinutes(int n, int headID,
                     vector<int>& manager,
                     vector<int>& informTime) {

        adj.resize(n);
        dp.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        return dfs(headID, informTime);
    }
};