class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> p;

        int maximum = INT_MIN;
        for (int i = 0; i < n; i++) {
            p.push({nums[i][0], {i, 0}});
            maximum = max(maximum, nums[i][0]);
        }

        int minimum = p.top().first;
        int r = maximum - minimum;
        ans = {minimum, maximum};

        while (p.size() == n) {
            auto temp = p.top();
            p.pop();
            int i = temp.second.first;
            int j = temp.second.second;

            if (j + 1 < nums[i].size()) {  
                p.push({nums[i][j+1], {i, j+1}}); 
                maximum = max(maximum, nums[i][j+1]);
                minimum = p.top().first;

                if (maximum - minimum < r) {
                    r = maximum - minimum;
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            }
        }
        return ans;
    }
};
