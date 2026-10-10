class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long) k1 + k2;
        vector<int> diff(n);
        int largest = 0;
        long long sumDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            largest = max(largest, diff[i]);
            sumDiff += diff[i];
        }

        if (sumDiff <= k) return 0;

        vector<long long> freq(largest + 1, 0);

        for (int value : diff) {
            freq[value]++;
        }

        for (int i = largest; i > 0 && k > 0; i--) {
            if (freq[i] == 0) continue;

            if (k >= freq[i]) {
                k -= freq[i];
                freq[i - 1] += freq[i];
                freq[i] = 0;
            } else {
                freq[i] -= k;
                freq[i - 1] += k;
                k = 0;
            }
        }

        long long result = 0;

        for (int i = 0; i <= largest; i++) {
            result += freq[i] * i * i;
        }

        return result;
    }
};