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
        if(rank[pu]>rank[pv]) parent[pv]=pu;
        else if(rank[pu]<rank[pv]) parent[pu]=pv;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>rank(n,0);
        vector<int>parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    unionbyrank(i,j,parent,rank);
                }
            }
        }
        unordered_set<int>set;
        for(int i=0;i<n;i++){
            set.insert(findParent(i,parent));
        }
        return set.size();
       
    }
};