class Solution {
public:
    bool Union(int a,int b, vector<int>&parent,vector<int>&rank){
        int x = findparent(a,parent);
        int y = findparent(b,parent);

        if(x == y){
            return true;
        }

        if(rank[x] > rank[y]){
            parent[y] = x;
        }
        else if(rank[x]<rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }

        return false;
    }

    int findparent(int a,vector<int>&parent){
        if(parent[a] == a)return a;
        else return parent[a] = findparent(parent[a],parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>rank(n+1,0);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }

        for(auto it:edges){
            if(Union(it[0],it[1],parent,rank))return it;
        }
        return {};
    }
};