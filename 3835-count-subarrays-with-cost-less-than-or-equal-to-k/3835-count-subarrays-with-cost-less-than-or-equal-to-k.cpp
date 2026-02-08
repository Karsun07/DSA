class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0;
        priority_queue<pair<long long,int>> high; 
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > low;

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            low.push({nums[r], r});
            high.push({nums[r], r});

            while (true) {
              
                while (!low.empty() && low.top().second < l) low.pop();
                while (!high.empty() && high.top().second < l) high.pop();

                long long small = low.top().first;
                long long big   = high.top().first;

                long long task = (big - small) * (r - l + 1LL);

                if (task <= k) break;

                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
