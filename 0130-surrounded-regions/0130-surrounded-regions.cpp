
class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int r, int c) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int r = board.size();
        int c = board[0].size();
        queue<pair<int,int>> q;

        // First column
        for(int i = 0; i < r; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'T';
                q.push({i,0});
            }
        }

        // Last column
        for(int i = 0; i < r; i++){
            if(board[i][c-1] == 'O'){
                board[i][c-1] = 'T';
                q.push({i,c-1});
            }
        }

        // First row
        for(int j = 0; j < c; j++){
            if(board[0][j] == 'O'){
                board[0][j] = 'T';
                q.push({0,j});
            }
        }

        // Last row
        for(int j = 0; j < c; j++){
            if(board[r-1][j] == 'O'){
                board[r-1][j] = 'T';
                q.push({r-1,j});
            }
        }

       
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int ni = i + row[k];
                int nj = j + col[k];
                if(valid(ni, nj, r, c) && board[ni][nj] == 'O'){
                    board[ni][nj] = 'T';
                    q.push({ni, nj});
                }
            }
        }

        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};
