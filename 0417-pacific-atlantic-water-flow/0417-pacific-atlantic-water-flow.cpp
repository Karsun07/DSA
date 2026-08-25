class Solution {
public:

    int r, c;

    vector<vector<int>> directions = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };


    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[i][j] = true;

        for(auto &d : directions) {

            int x = i + d[0];
            int y = j + d[1];


            if(x < 0 || x >= r || y < 0 || y >= c)
                continue;


            if(visited[x][y])
                continue;


            // reverse flow: ocean -> higher/equal height
            if(heights[x][y] < heights[i][j])
                continue;


            dfs(x, y, heights, visited);
        }
    }



    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        r = heights.size();
        c = heights[0].size();


        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));


        // Pacific: top row
        for(int j = 0; j < c; j++) {
            dfs(0, j, heights, pacific);
        }


        // Pacific: left column
        for(int i = 0; i < r; i++) {
            dfs(i, 0, heights, pacific);
        }


        // Atlantic: bottom row
        for(int j = 0; j < c; j++) {
            dfs(r-1, j, heights, atlantic);
        }


        // Atlantic: right column
        for(int i = 0; i < r; i++) {
            dfs(i, c-1, heights, atlantic);
        }



        vector<vector<int>> result;


        for(int i = 0; i < r; i++) {

            for(int j = 0; j < c; j++) {

                if(pacific[i][j] && atlantic[i][j]) {

                    result.push_back({i,j});
                }
            }
        }


        return result;
    }
};