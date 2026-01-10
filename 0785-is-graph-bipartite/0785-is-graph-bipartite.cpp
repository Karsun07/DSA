class Solution {
public:
    bool dfs(int node,int c,vector<vector<int>>&adj,vector<int>&color){
        color[node]=c;
        for(int j=0;j<adj[node].size();j++){
            int nb=adj[node][j];
            if(color[nb]==-1){
                if(!dfs(nb,(color[node]+1)%2,adj,color)) return 0;
            }
            else{
                if(color[nb]==color[node]) return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& adj) {
       int V=adj.size();
       vector<int>color(V,-1);
       for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(!dfs(i,0,adj,color)) return 0;
        }
       }
       return 1;

    }
};