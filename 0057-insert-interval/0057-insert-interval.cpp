class Solution {
public:
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
    vector<vector<int>> ans;

    void merge() {
        while (p.size() > 1) {
            auto a = p.top(); p.pop();
            auto b = p.top(); p.pop();

            int x1 = a.first, y1 = a.second;
            int x2 = b.first, y2 = b.second;

            if (y1 >= x2) {
                p.push({x1, max(y1, y2)});
            } else {
                ans.push_back({x1, y1});
                p.push(b);
            }
        }

        if (!p.empty()) {
            auto last = p.top();
            ans.push_back({last.first, last.second});
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInterval) {
        

        for(int i=0;i<inter.size();i++) {
            p.push({inter[i][0], inter[i][1]});
        }
        p.push({newInterval[0], newInterval[1]});

        merge();
        return ans;
    }
};