class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        int maxf = 0;
        vector<int> freq(k, 0);

        set<int> available;
        for(int i = 0; i < k; i++) available.insert(i);

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        for(int i = 0; i < n; i++) {

            while(!pq.empty() && pq.top().first <= arrival[i]) {
                available.insert(pq.top().second);
                pq.pop();
            }

            if(available.empty()) continue;

            int start = i % k;

            auto it = available.lower_bound(start);

            if(it == available.end()) it = available.begin();

            int server = *it;

            available.erase(it);  // Important!

            freq[server]++;
            maxf = max(maxf, freq[server]);

            pq.push({arrival[i] + load[i], server});
        }

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(freq[i] == maxf) ans.push_back(i);
        }

        return ans;
    }
};