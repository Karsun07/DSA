class Solution {
public:
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
        int n = words.size();

        sort(words.begin(), words.end(), cmp);

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {
                if (match(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};