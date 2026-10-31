class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        dist[0][1] = 0;

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        // {dist, {node, consecutive}}
        pq.push({0, {0, 1}});

        while(!pq.empty()) {

            auto x = pq.top();
            pq.pop();

            int d = x.first;
            int node = x.second.first;
            int cons = x.second.second;

            if(node == n-1)
                return d;

            for(auto x : adj[node]) {

                int nb = x.first;
                int wt = x.second;

                int newCons;

                if(labels[node] == labels[nb])
                    newCons = cons + 1;
                else
                    newCons = 1;

                if(newCons > k)
                    continue;

                if(d + wt < dist[nb][newCons]) {

                    dist[nb][newCons] = d + wt;

                    pq.push({
                        dist[nb][newCons],
                        {nb, newCons}
                    });
                }
            }
        }

        return -1;
    }
};