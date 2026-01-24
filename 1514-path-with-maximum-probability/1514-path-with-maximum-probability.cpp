class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       vector<double>dist(n,0);
       dist[start]=1;
       vector<vector<pair<int,double>>>adj(n);
       for(int i=0;i<edges.size();i++){
          int u=edges[i][0],v=edges[i][1];
          double wt=succProb[i];
          adj[u].push_back({v,wt});
          adj[v].push_back({u,wt});
       }
       
       priority_queue<pair<double,int>>pq;
       pq.push({1,start});
       while(!pq.empty()){
        auto [pro,node]=pq.top();
        pq.pop();
        if(pro<dist[node]) continue;
        for(int j=0;j<adj[node].size();j++){
            int nb=adj[node][j].first;
            double wt=adj[node][j].second;
            if(pro*wt>dist[nb]){
                dist[nb]=pro*wt;
                pq.push({dist[nb],nb});
            }

        }
       }
       return dist[end];
    }
};