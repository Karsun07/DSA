class Solution {
public:
    int findParent(int u,vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u],parent);
    }
    void unionByRank(int u,int v,vector<int>&rank,vector<int>&parent){
        int pu=findParent(u,parent);
        int pv=findParent(v,parent);
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        // {dist,{i,j}}
        // pair<int,pair<int,int>>
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       for(int i=0;i<points.size()-1;i++){
        for(int j=i+1;j<points.size();j++){
            int x1=points[i][0],y1=points[i][1];
            int x2=points[j][0],y2=points[j][1];
            int dist=abs(x1-x2)+abs(y1-y2);
            pq.push({dist,{i,j}});
        }
       }
       int n=points.size();
       vector<int>parent(n);
       for(int i=0;i<n;i++) parent[i]=i;
       vector<int>rank(n,0);
       int cost=0,edg=0;
       while(!pq.empty()){
          auto x=pq.top();
          pq.pop();
          int dist=x.first;
          int u=x.second.first;
          int v=x.second.second;
          if(findParent(u,parent)!=findParent(v,parent)){
            //disjoint sets
            cost+=dist;
            edg++;
            unionByRank(u,v,rank,parent);
          }
          if(edg==n-1) return cost;
       }
       return 0;



    }
};