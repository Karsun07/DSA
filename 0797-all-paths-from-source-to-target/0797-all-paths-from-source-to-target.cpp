class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node,int target,vector<vector<int>>&adj,vector<int>&path){
       
        path.push_back(node);
        if(node==target) ans.push_back(path);
        for(int j=0;j<adj[node].size();j++){
           
                
                dfs(adj[node][j],target,adj,path);
           
        }
      
        path.pop_back();
        

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int V=adj.size();
        
        vector<int>path;
        
        dfs(0,V-1,adj,path);
        return ans;
    }
};