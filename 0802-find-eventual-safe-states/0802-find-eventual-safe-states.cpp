class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>revg(graph.size());
        vector<int>indeg(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int u=graph[i][j],v=i;
                revg[u].push_back(v);
                indeg[v]++;
            }
        }
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(!indeg[i]) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int j=0;j<revg[node].size();j++){
                int nb=revg[node][j];
                indeg[nb]--;
                if(indeg[nb]==0) q.push(nb);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};