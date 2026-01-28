class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
       
     
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        // k+1 nodes including dst=>size=>k+2
        // {cost,{stops,node}}
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[src][0]=0;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int cost=x.first;
            int stops=x.second.first;
            int node=x.second.second;
            if(node==dst) return cost;
            if(stops>k) continue;
            for(auto &it:adj[node]){
                int nb=it.first;
                int price=it.second;
                if(cost+price<dist[nb][stops+1]){
                    dist[nb][stops+1]=cost+price;
                    pq.push({dist[nb][stops+1],{stops+1,nb}});
                }
            }
        }
        return -1;
    }
};