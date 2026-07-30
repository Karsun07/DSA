class Solution {
public:
    long long nCr(int n, int r, long long limit) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res >= limit) return limit;
        }

        return res;
    }

    long long getMeTheWays(int len, vector<int>& freq, long long limit) {
        long long ans = 1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            long long comb = nCr(len, freq[i], limit);

            if (comb == 0) return 0;

            if (ans >= limit || comb >= limit || ans > limit / comb)
                ans = limit;
            else
                ans *= comb;

            len -= freq[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int halfLen = n / 2;
        char mid = s[halfLen];

        vector<int> freq(26, 0);
        for (int i = 0; i < halfLen; i++)
            freq[s[i] - 'a']++;

        long long K = k;

        if (getMeTheWays(halfLen, freq, K) < K)
            return "";

        string ans;

        for (int i = 0; i < halfLen; i++) {
            for (int j = 0; j < 26; j++) {
                if (freq[j] == 0) continue;

                freq[j]--;

                long long ways = getMeTheWays(halfLen - i - 1, freq, K);

                if (K <= ways) {
                    ans.push_back(char('a' + j));
                    break;
                }

                freq[j]++;
                K -= ways;
            }
        }

        string rev = ans;
        reverse(rev.begin(), rev.end());

        if (n % 2)
            return ans + mid + rev;
        return ans + rev;
    }
};