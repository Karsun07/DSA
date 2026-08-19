class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowcheck[9][9] = {0};
        int colcheck[9][9] = {0};
        int gridcheck[9][9] = {0};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1; // convert '1'-'9' to 0-8
                    int k = (i / 3) * 3 + (j / 3);   // grid number 0–8

                    // check the three condition ,for repeatition
                    rowcheck[i][num]++;
                    colcheck[j][num]++;
                    gridcheck[k][num]++;
                    if (rowcheck[i][num]==2|| colcheck[j][num]==2 || gridcheck[k][num]==2)
                        return false;
                }
            }
        }
        return true;
    }
};
