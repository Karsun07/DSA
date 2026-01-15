class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        vector<vector<int>> dist(r, vector<int>(c, -1));
        queue<pair<int,int>> q;

       
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int ni = i + row[k];
                int nj = j + col[k];

                if(ni >= 0 && nj >= 0 && ni < r && nj < c && dist[ni][nj] == -1){
                    dist[ni][nj] =dist[i][j]+1;
                    q.push({ni, nj});
                }
            }
        }
        return dist;
    }
};
