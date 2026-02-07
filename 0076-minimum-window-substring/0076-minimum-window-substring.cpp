class Solution {
public:
    string minWindow(string s, string t) {
        int total = t.size();
        unordered_map<char,int> mp;

        // build from t, not s
        for(char c : t){
            mp[c]++;
        }

        int l = 0;
        int start = -1;
        int size = INT_MAX;

        for(int r = 0; r < s.size(); r++){
            mp[s[r]]--;
            if(mp[s[r]] >= 0) total--;

            while(total == 0){
                if(size > r - l + 1){
                    size = r - l + 1;
                    start = l;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0) total++;
                l++;
            }
        }

        if(start == -1) return "";
        return s.substr(start, size);
    }
};
