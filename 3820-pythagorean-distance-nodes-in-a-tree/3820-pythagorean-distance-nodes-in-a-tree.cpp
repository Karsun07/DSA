class Solution {
public:
    vector<int>bfs(int start,vector<vector<int>>&adj){
        vector<int>dist(adj.size(),-1);
        dist[start]=0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                for(int j=0;j<adj[node].size();j++){
                    int nb=adj[node][j];
                    if(dist[nb]==-1){
                        dist[nb]=dist[node]+1;
                        q.push(nb);
                    }
                }
            }
        }
        return dist;


    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
       vector<vector<int>>adj(n);
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0],v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<int>arr1=bfs(x,adj);
       vector<int>arr2=bfs(y,adj);
       vector<int>arr3=bfs(z,adj);
       int ans=0;
       for(int i=0;i<n;i++){
        long long a=arr1[i],b=arr2[i],c=arr3[i];
        long long maxi=max({a,b,c});
        if(a*a+b*b+c*c==2*maxi*maxi) ans++;
       }
       return ans;
    }
};