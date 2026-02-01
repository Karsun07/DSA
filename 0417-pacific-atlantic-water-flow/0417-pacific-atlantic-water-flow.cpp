class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    bool valid(int i,int j,int r,int c){
        return i>=0 && j>=0 && i<r && j<c;
    }
  vector<vector<bool>> solve(vector<vector<int>>& heights, int type) {
    int r = heights.size(), c = heights[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<pair<int,int>> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!type && (i == 0 || j == 0)) {           
                q.push({i, j});
                visited[i][j] = true;
            }
            else if (type && (i == r-1 || j == c-1)) {     
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];
            if (valid(ni, nj, r, c) &&
                !visited[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
    return visited;
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size(),c=heights[0].size();
        // 0=>pacific ,1=>atlantic
        vector<vector<bool>>pacific=solve(heights,0);
        vector<vector<bool>>atlantic=solve(heights,1);
        vector<vector<int>>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j]&&atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
        
    }
};