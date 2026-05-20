class Solution {
public:
    int dp[1001][1001];

    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }

    bool match(string &a, string &b) {
        if (b.size() != a.size() + 1)
            return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                if (skipped)
                    return false;

                skipped = true;
                j++;
            }
        }

        return true;
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), cmp);

        int n = words.size();
        for (int j = 0; j <= n; j++) {
            dp[n][j] = 0;
        }
        for (int curr = n - 1; curr >= 0; curr--) {

            for (int prev = curr - 1; prev >= -1; prev--) {

                int take = 0;

                if (prev == -1 || match(words[prev], words[curr])) {
                    take = 1 + dp[curr + 1][curr + 1];
                }

                int nottake = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, nottake);
            }
        }

        return dp[0][0];
    }
};