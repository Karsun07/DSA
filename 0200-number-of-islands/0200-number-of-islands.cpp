class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int r, int c) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {   
                if(grid[i][j] == '1') {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    ans++;

                    while(!q.empty()) {
                        auto [i1, j1] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int i2 = i1 + row[k];
                            int j2 = j1 + col[k];

                            if(valid(i2, j2, r, c) && grid[i2][j2] == '1') { 
                                q.push({i2, j2});
                                grid[i2][j2] = '0';
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
