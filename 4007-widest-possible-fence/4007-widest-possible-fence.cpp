class Solution {
public:
    int maximumWidth(vector<int>& v) {
        map<int, int> mp;

        int n = v.size();

        for(auto &x : v) mp[x] += 1;

        vector<pair<int, int>> a(mp.begin(), mp.end());
        // element,freq
        auto fr = mp;

        for(int i = 0;i < a.size();i += 1){

            auto [x, fx] = a[i];
            
            for(int j = i + 1;j < a.size();j += 1){
                auto [y, fy] = a[j];

                mp[x + y] += min(fx, fy);
            }

            mp[2 * x] += fx/2;
        }

        int ans = 0;
        for(auto &[x, y] : mp){
            ans = max(ans, y);
        }

        return ans;
    }
};