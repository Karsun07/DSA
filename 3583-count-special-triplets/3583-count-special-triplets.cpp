class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
                

        unordered_map<long long,long long> r, l;
        for (int i = 0; i < n; i++) {
            r[nums[i]]++;
        }

        const long long mod = 1000000007LL;
        r[nums[0]]--;
        long long prev = nums[0];
        long long ans = 0;

        for (int j = 1; j < n; j++) {
            r[nums[j]]--;
            l[prev]++;
            long long req = (long long)nums[j] * 2LL;
            ans = (ans + ( (l[req] * r[req]) % mod )) % mod;
            prev = nums[j];
        }
        return (int)ans;
    }
};
