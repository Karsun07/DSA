class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        if(numCourses==1) return true;
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
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int j=0;j<adj[node].size();j++){
                int nb=adj[node][j];
                indeg[nb]--;
                if(indeg[nb]==0) q.push(nb);
            }
        }
        if(count==V) return true;
        else return false;
    }
};