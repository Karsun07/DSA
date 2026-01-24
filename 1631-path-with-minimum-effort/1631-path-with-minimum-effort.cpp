class Solution {
public:
    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        while(!pq.empty()){
            auto x=pq.top();
            int cost=x.first;
            int i=x.second.first;
            int j=x.second.second;
            pq.pop();
            if(cost>dist[i][j]) continue;
            if(i==r-1 && j==c-1) return cost;
            for(int k=0;k<4;k++){
                int i1=i+row[k];
                int j1=j+col[k];
                if(valid(i1,j1,r,c)){
                    int effort=max(cost,abs(heights[i][j]-heights[i1][j1]));
                    if(effort<dist[i1][j1]){
                        dist[i1][j1]=effort;
                        pq.push({effort,{i1,j1}});
                    }
                }  
            }
        }
        return 0;
        
       
    }
};