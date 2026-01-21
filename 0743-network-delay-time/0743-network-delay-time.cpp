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

        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0; 

        int x = n - 1;
        while(x--) {
            bool change = 0;
            for(auto &it : times) {
                int u = it[0] - 1;   
                int v = it[1] - 1;   
                int wt = it[2];

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    change = 1;
                    dist[v] = dist[u] + wt;
                }
            }
            if(!change) break;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {      
            if (dist[i] == INT_MAX) return -1;  
            res = max(res, dist[i]);
        }
        return res;
    }
};
