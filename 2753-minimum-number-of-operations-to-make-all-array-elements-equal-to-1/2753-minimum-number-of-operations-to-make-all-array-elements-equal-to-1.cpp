class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums) {
            if (x == 1) ones++;
        }
        if (ones > 0) {
            return n - ones;
        }
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    best = min(best, j - i);
                    break; 
                }
            }
        }

        
        if (best == INT_MAX) return -1;

       
        return best + n - 1;
    }
};
