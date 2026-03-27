class Solution {
public:
    int n1, n2;

    int fun(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        if(i >= n1 || j >= n2) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + fun(i + 1, j + 1, text1, text2, dp);
        }

        return dp[i][j] = max(
            fun(i + 1, j, text1, text2, dp),
            fun(i, j + 1, text1, text2, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size();
        n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return fun(0, 0, text1, text2, dp);
    }
};