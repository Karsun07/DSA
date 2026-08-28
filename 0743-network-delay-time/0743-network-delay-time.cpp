class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        for(int i=0;i<n-1;i++){

            for(auto ed:times){
                int u=ed[0]-1,v=ed[1]-1,t=ed[2];

                if(dist[u]!=INT_MAX && dist[u]+t<dist[v]){
                    dist[v]=dist[u]+t;
                }
            }
        }
        int total=0;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX) return -1;
            total=max(total,dist[i]);
        }
        return total;
        
    }
};
