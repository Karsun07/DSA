class Solution {
public:
    int dp[1001][1001];
    
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }

    bool match(string &w1, string &w2) {
        if(w2.size() != w1.size() + 1) return false;
        int i = 0, j = 0, skip = 0;
        while(i < w1.size() && j < w2.size()) {
            if(w1[i] != w2[j]) {
                skip++;
                j++;
            } else {
                i++;
                j++;
            }
        }
        return skip <= 1 && i == w1.size();
    }

    int fun(int curr, int prev, vector<string>& words) {
        if(curr >= words.size()) return 0;

        if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

        int take = 0;
        if(prev == -1 || match(words[prev], words[curr])) {
            take = 1 + fun(curr + 1, curr, words);
        }
        int nottake = fun(curr + 1, prev, words);

        return dp[curr][prev + 1] = max(take, nottake);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        memset(dp, -1, sizeof(dp));
        return fun(0, -1, words);
    }
};