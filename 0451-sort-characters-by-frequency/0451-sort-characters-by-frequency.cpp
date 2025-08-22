class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>freq;
       int n=s.size();
       for(int i=0;i<n;i++){
        freq[s[i]]++;
       }
       vector<vector<char>>buckets(n+1);
       for(auto &p:freq){
        buckets[p.second].push_back(p.first);
       }
       string ans = "";
        for (int i = n; i >= 1; i--) {         
            if (!buckets[i].empty()) {         
                for (int j = 0; j < buckets[i].size(); j++) {
                    char c = buckets[i][j];
                    int repeat = i;
                    while (repeat--) {         
                        ans += c;
                    }
                }
            }
        }
       return ans;


    }
};