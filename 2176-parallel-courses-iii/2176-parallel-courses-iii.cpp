class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>>adj(n);
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indeg[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indeg[i]) q.push(i);
        }
        //max time to complete prev course
        vector<int>coursetime(n,0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]]) q.push(adj[node][j]);

                coursetime[adj[node][j]]=max(coursetime[adj[node][j]],coursetime[node]+time[node]);

            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,coursetime[i]+time[i]);
        }
        return ans;










    }
};