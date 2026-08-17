class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();

        unordered_map<char,int> mp1;
        for(int i = 0; i < t.size(); i++)
            mp1[t[i]]++;

        unordered_map<char,int> mp2;

        int l = 0;
        int r = 0;

        int count = 0;  
        int start = 0;
        int len = INT_MAX;

        while(r < n) {

            if(mp1.count(s[r])) {
                mp2[s[r]]++;

                if(mp2[s[r]] <= mp1[s[r]])
                    count++;
            }
            while(count == t.size()) {

                if(r-l+1 < len) {
                    len = r-l+1;
                    start = l;
                }
                if(mp1.count(s[l])) {
                    mp2[s[l]]--;
                    if(mp2[s[l]] < mp1[s[l]])
                        count--;
                }
                l++;
            }
            r++;
        }

        return len == INT_MAX ? "" : s.substr(start,len);
    }
};