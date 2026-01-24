class Solution {
public:
    bool valid(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
       queue<pair<int,int>>q;
       q.push({0,0});
       int n=heights.size();
       vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
       dist[0][0]=0;
       int row[4] = {-1,1,0,0};
       int col[4] = {0,0,-1,1};
       while(!q.empty()){
         int i=q.front().first;
         int j=q.front().second;
         q.pop();
         for(int k=0;k<4;k++){
            int i1=i+row[k];
            int j1=j+col[k];
            if(valid(i1,j1,r,c)){
                int effort=max(dist[i][j],abs(heights[i][j]-heights[i1][j1]));
                if(effort<dist[i1][j1]){
                    dist[i1][j1]=effort;
                    q.push({i1,j1});
                }
            }
         }
       }
       return dist[r-1][c-1];

    }
};