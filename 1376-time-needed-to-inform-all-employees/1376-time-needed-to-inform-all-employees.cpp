class Solution {
public: 
    long long ans=INT_MIN;
    void dfs(int man,long long cost,vector<vector<int>>&adj,vector<int>&informTime){
        if(adj[man].empty()){
            ans=max(ans,cost);
            return;
        }
        for(int &emp:adj[man]){
            dfs(emp,cost+1LL*informTime[man],adj,informTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        int man=-1;
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        dfs(headID, 0, adj, informTime);
        return ans;

    }
};