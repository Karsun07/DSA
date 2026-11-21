class Solution {
public:
    vector<vector<int>> adj, newAdj;
    vector<int> last, result;

    void dfs(int node, string &s, vector<int>& parent) {
        int c = s[node] - 'a';

        int prev = last[c];

        if (node != 0 && prev != -1) {
            parent[node] = prev;
        }

        last[c] = node;

        for (int child : adj[node]) {
            dfs(child, s, parent);
        }

        last[c] = prev;
    }

    int calculateSize(int node) {
        int size = 1;

        for (int child : newAdj[node]) {
            size += calculateSize(child);
        }

        return result[node] = size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newAdj.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        last.assign(26, -1);

        dfs(0, s, parent);

        for (int i = 1; i < n; i++) {
            newAdj[parent[i]].push_back(i);
        }

        result.assign(n, 0);

        calculateSize(0);

        return result;
    }
};