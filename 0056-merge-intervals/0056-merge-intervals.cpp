class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        if (n < 2) return inter;

        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;

        for (int i = 0; i < n; i++) {
            p.push({inter[i][0], inter[i][1]});
        }

        vector<vector<int>> ans;

        while (p.size() > 1) {
            auto a = p.top(); p.pop();
            auto b = p.top(); p.pop();

            int x1 = a.first, y1 = a.second;
            int x2 = b.first, y2 = b.second;

            if (y1 >= x2) {
               
                p.push({min(x1, x2), max(y1, y2)});
            } else {
                
                ans.push_back({x1, y1});
                p.push({x2, y2});
            }
        }

      
        if (!p.empty()) {
            auto last = p.top();
            ans.push_back({last.first, last.second});
        }

        return ans;
    }
};
