class Solution {
public:
    int fun(unordered_map<int,int>& m, int x) {
        priority_queue<pair<int,int>> p;
        for (auto& it : m) {
            p.push({it.second, it.first});
        }
        int sum = 0;
        while (x-- && !p.empty()) {
            auto y = p.top();
            int fr=y.first;
            int num=y.second;
            p.pop();
            sum += num * fr;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> m;
        int n = nums.size();
        if (k > n) return {};
        vector<int> ans;
        int l = 0;
        for (int r = 0; r < n; r++) {
            m[nums[r]]++;
            if (r - l + 1 > k) {
                m[nums[l]]--;
                if (m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            if (r - l + 1 == k) {
                ans.push_back(fun(m, x));
            }
        }

        return ans;
    }
};
