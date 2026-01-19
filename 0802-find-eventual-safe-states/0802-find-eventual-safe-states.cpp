class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<bool>& path, vector<bool>& incyc, vector<bool>& vis) {

        if (path[node]) {         
            incyc[node] = 1;
            return true;
        }

        if (vis[node])           
            return incyc[node];

        vis[node] = 1;
        path[node] = 1;

        for (int j = 0; j < graph[node].size(); j++) {
            int nxt = graph[node][j];
            if (dfs(nxt, graph, path, incyc, vis)) {
                incyc[node] = 1;  
            }
        }

        path[node] = 0;          
        return incyc[node];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> path(n, 0), incyc(n, 0), vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, graph, path, incyc, vis);
        }

        vector<int> safe;
        for (int i = 0; i < n; i++) {
            if (!incyc[i]) safe.push_back(i);
        }
        return safe;
    }
};
