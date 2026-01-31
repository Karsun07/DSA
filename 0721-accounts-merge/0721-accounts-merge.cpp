class Solution {
public:
    int findParent(int u,vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u],parent);
    }
    void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank){
        int pu=findParent(u,parent);
        int pv=findParent(v,parent);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<int>rank(n,0);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.find(email)!=mp.end()){
                    unionbyrank(i,mp[email],parent,rank);
                }
                else{
                    mp[email]=i;
                }
            }
        }
        vector<vector<string>>temp(n);
        for(auto &it:mp){
            int ultimateParent=findParent(it.second,parent);
            temp[ultimateParent].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(temp[i].empty()) continue;
            sort(temp[i].begin(),temp[i].end());
            string acc=accounts[i][0];
            vector<string>row;
            row.push_back(acc);
            for(auto it:temp[i]){
                row.push_back(it);
            }
            ans.push_back(row);
        }
        return ans;
    }
};