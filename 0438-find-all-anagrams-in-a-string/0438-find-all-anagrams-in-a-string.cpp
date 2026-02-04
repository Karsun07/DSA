class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int win = p.size();

        if (win > n) return {};

        unordered_map<char,int> mp;
        for (int i = 0; i < win; i++) {
            mp[p[i]]++;
        }

        unordered_map<char,int> temp;
        int l = 0, r = 0;
        vector<int> ans;

        while (r < n) {
            temp[s[r]]++;
            r++;

            if (r - l == win) {       
                if (temp == mp) ans.push_back(l);

                temp[s[l]]--;          
                if (temp[s[l]] == 0) temp.erase(s[l]);
                l++;
            }
        }

        return ans;
    }
};
