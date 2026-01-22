class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {src, 0}});
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int cost = cur.first;
            int node = cur.second.first;
            int stops = cur.second.second;

            if (node == dst) return cost;
            if (stops == k + 1) continue;

            for (auto &e : adj[node]) {
                int next = e.first;
                int wt = e.second;
                if (cost + wt < dist[next][stops + 1]) {
                    dist[next][stops + 1] = cost + wt;
                    pq.push({cost + wt, {next, stops + 1}});
                }
            }
        }

        return -1;
    }
};
