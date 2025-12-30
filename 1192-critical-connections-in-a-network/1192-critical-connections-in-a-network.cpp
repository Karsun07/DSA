class Solution {
public:
    int counter = 0; 
    vector<vector<int>> ans;
    int m;
    vector<int> low;   // lowest index reachable
    vector<int> disc;  // discovery time

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        low[node] = disc[node] = counter;

        for (int j = 0; j < adj[node].size(); j++) {
            int nb = adj[node][j];
            if (nb == parent) continue;

            if (visited[nb]) {
               
                low[node] = min(low[node], disc[nb]);
            } 
            else {
                counter++;
                dfs(nb, node, adj, visited);

                low[node] = min(low[node], low[nb]);

                
                if (low[nb] > disc[node]) {
                    ans.push_back({nb, node});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        m = n;
        low.resize(m);
        disc.resize(m);

        vector<vector<int>> adj(n);

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(m, 0);
        dfs(0, -1, adj, visited);

        return ans;
    }
};
