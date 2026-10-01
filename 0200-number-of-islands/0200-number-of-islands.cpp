class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); 
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m * n);
        rankv.assign(m * n, 0);

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;

                parent[id] = id;

                if (grid[i][j] == '1')
                    islands++;
            }
        }

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0')
                    continue;

                int id1 = i * n + j;

                // Only check right and down
                for (int k = 0; k < 2; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni < m && nj < n && grid[ni][nj] == '1') {

                        int id2 = ni * n + nj;

                        if (find(id1) != find(id2)) {
                            unite(id1, id2);
                            islands--;
                        }
                    }
                }
            }
        }

        return islands;
    }
};