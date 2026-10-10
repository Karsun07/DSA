class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long sum = 0, maxDiff = 0;
        long long k = (long long)k1 + k2;
        unordered_map<long long, long long> mp;

        for (int i = 0; i < n; i++) {
            long long d = abs(nums1[i] - nums2[i]);
            mp[d]++;
            maxDiff = max(maxDiff, d);
            sum += d;
        }
        if (sum <= k) return 0;

        while (k > 0 && maxDiff > 0) {
            long long x = mp[maxDiff];
            if (x <= k) {
                k -= x;                     
                mp[maxDiff - 1] += x;
                mp[maxDiff] = 0;
                maxDiff--;
            } else {
                mp[maxDiff - 1] += k;        
                mp[maxDiff] -= k;
                k = 0;
            }
        }

        long long ans = 0;
        for (auto &it : mp) {
            long long val = it.first, cnt = it.second;
            ans += cnt * val * val;
        }
        return ans;
    }
};