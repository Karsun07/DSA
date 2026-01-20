class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int>indeg(n,0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==1) q.push(i);
        }
        int nodes=n;
        while(nodes>2){
           int sz=q.size();
           nodes-=sz;
           for(int i=0;i<sz;i++){
             int node=q.front();
             q.pop();
             for(int j=0;j<adj[node].size();j++){
                int nb=adj[node][j];
                indeg[nb]--;
                if(indeg[nb]==1) q.push(nb);
             }

           }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

    }
};
