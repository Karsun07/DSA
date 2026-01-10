class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int V=n;
        if(V==1) return 0;
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            int u=manager[i],v=i;
            if(u!=-1) adj[u].push_back(v);
        }
        int totalTime=0;
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            int man=q.front().first;
            int time=q.front().second;
            q.pop();
            totalTime=max(totalTime,time);
            for(int j=0;j<adj[man].size();j++){
                int emp=adj[man][j];
                q.push({emp,time+informTime[man]});
            }
        }
        return totalTime;

    }
};