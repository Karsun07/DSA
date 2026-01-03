class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>prevTime(n,0);//time taken before completion of ith task
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            indeg[relations[i][1]-1]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                int nb=adj[node][j];
                indeg[nb]--;
                if(indeg[nb]==0) q.push(nb);
                prevTime[nb]=max(prevTime[nb],time[node]+prevTime[node]);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,prevTime[i]+time[i]);
        }
        return ans;

       
    }
};