class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        if(numCourses==1) return {0};
        int V=numCourses;
        vector<vector<int>>adj(V);
        vector<int>indeg(V,0);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int j=0;j<adj[node].size();j++){
                int nb=adj[node][j];
                indeg[nb]--;
                if(indeg[nb]==0) q.push(nb);
            }
        }
        if(ans.size()==V) return ans;
        else return {};


    }
};