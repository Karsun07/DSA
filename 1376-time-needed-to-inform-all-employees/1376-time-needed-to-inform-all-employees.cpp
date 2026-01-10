class Solution {
public:
    
    int dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&informTime){
        int ans=0;
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]]){
                ans=max(ans,informTime[node]+dfs(adj[node][j],adj,visited,informTime));
            }
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int V=n;
        if(V==1) return 0;
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            int u=manager[i],v=i;
            if(u!=-1) adj[u].push_back(v);
        }
        vector<bool>visited(V,0);
        return dfs(headID,adj,visited,informTime);

    }
};