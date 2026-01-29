class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=1;
        for(int j=0;j<adj[node].size();j++){
            int nb=adj[node][j];
            if(!visited[nb]){
                dfs(nb,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                ans++;
            }
        }
        return ans;
    }
};