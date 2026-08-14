class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26, 0), b(26, 0), ans;
        if(s1.size()>s2.size()){
            return 0;
        }
        for(int i = 0; i < s1.size(); i++){
            a[s1[i]-'a']++;
        }
        int win = s1.size();
        int l=0,r=0;
        int n=s2.size();
        while(r<n){
            b[s2[r]-'a']++;
            if(r-l+1==win){
                if(a==b) return true;
                b[s2[l]-'a']--;
                l++;     
            }
            r++;
        }
        return false;
        
        
    }
};