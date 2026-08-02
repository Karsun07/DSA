class Solution {
public:
    long long minInitialStrength(vector<int>& v, vector<vector<int>>& arr) {

        int n = v.size();

        vector<long long> a(n + 1);

        for(auto &x : arr){
            int l = x[0], r = x[1], value = x[2];

            a[l] += value;
            a[r + 1] -= value;
        }

        for(int i = 1;i <= n;i += 1){
            a[i] += a[i - 1];
        }

        long long ans = 0, done = 0;

        for(int i = 0;i < n;i += 1){
            // a[i] + st >= v[i]

            if(a[i] < v[i]){
                ans = max(ans, v[i] - a[i] + done);
            }

            done += v[i];
        }

        return ans;
        
    }
};