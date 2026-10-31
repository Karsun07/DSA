class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int,pair<int,int>>> q;
        // {stops, {node, dist}}

        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()) {

            auto x = q.front();
            q.pop();

            int stops = x.first;
            int node = x.second.first;
            int d = x.second.second;

            if(stops > k)
                continue;

            for(auto it : adj[node]) {

                int v = it.first;
                int wt = it.second;

                if(d + wt < dist[v]) {

                    dist[v] = d + wt;

                    q.push({
                        stops + 1,
                        {v, dist[v]}
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};