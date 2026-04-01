class Solution {
public:
    int ns, nt;
    long long dp[1001][1001];

    long long fun(int i, int j, string &s, string &t) {
        if (j == nt) return 1;
        if (i == ns) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        long long count = 0;

        if (s[i] == t[j]) {
            count += fun(i + 1, j + 1, s, t);
        }

        count += fun(i + 1, j, s, t);

        return dp[i][j] = count;
    }

    int numDistinct(string s, string t) {
        ns = s.size();
        nt = t.size();

        for (int i = 0; i <= ns; i++) {
            for (int j = 0; j <= nt; j++) {
                dp[i][j] = -1;
            }
        }

        return fun(0, 0, s, t);
    }
};