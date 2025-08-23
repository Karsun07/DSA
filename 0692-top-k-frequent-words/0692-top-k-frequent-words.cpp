class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        int n = words.size();

        
        for (int i = 0; i < n; i++) {
            freq[words[i]]++;
        }

        
        vector<vector<string>> buckets(n+1);
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        vector<string> ans;
        
        for (int i = n; i >= 0 && ans.size() < k; i--) {
            if (!buckets[i].empty()) {
               
                sort(buckets[i].begin(), buckets[i].end());

                for (int j = 0; j < buckets[i].size() && ans.size() < k; j++) {
                    ans.push_back(buckets[i][j]);
                }
            }
        }
        return ans;
    }
};
