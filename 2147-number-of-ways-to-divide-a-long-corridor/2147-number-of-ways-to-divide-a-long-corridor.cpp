class Solution {
public:
    int numberOfWays(string corr) {
        const int MOD = 1e9 + 7;
        int n = corr.size();
        int i = 0;
        vector<vector<int>> store;
        while (i < n) {
            if (corr[i] == 'P') {
                i++;                 
                continue;
            }
            int req = 2;
            int j = i;
            while (j < n && req != 0) {
                if (corr[j] == 'S') req--;
                j++;                 
            }
            if (req != 0) return 0; 
            store.push_back({i, j - 1});
            i = j;                   
        }
        long long ans = 1;
        for (int k = 0; k < (int)store.size() - 1; k++) {
            int first = store[k][1];
            int second = store[k + 1][0];
            int gap = second - first ; 
            ans = (ans * gap) % MOD;       
        }
        return store.empty() ? 0 : ans;
    }
};
