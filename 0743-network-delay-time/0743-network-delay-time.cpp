class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];  
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);

        dist[k-1] = 0;             
        pq.push({0, k-1});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &edge : adj[node]){
                int nb = edge.first;
                int wt = edge.second;

                if(dist[nb] > dist[node] + wt){
                    dist[nb] = dist[node] + wt;
                    pq.push({dist[nb], nb});
                }
            }
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX) return -1;  
            total = max(total, dist[i]);
        }

        return total;
    }
};
