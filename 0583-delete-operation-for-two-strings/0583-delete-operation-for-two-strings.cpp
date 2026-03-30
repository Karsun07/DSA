class Solution {
public:
    int n1, n2;

    int lcs(int i, int j, string &word1, string &word2, vector<vector<int>>& dp) {
        if (i >= n1 || j >= n2) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = 1 + lcs(i + 1, j + 1, word1, word2, dp);
        }

        return dp[i][j] = max(
            lcs(i + 1, j, word1, word2, dp),
            lcs(i, j + 1, word1, word2, dp)
        );
    }

    int minDistance(string word1, string word2) {
        n1 = word1.size();   
        n2 = word2.size();   

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        int common = lcs(0, 0, word1, word2, dp);

        return (n1 - common) + (n2 - common);
    }
};