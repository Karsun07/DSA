class Solution {
public:
    string minWindow(string s, string t) {
        int size=INT_MAX, l=0,r=0,index=-1;
        unordered_map<char,int>m;
        int total=t.size(),n=s.size();
        for(int i=0;i<total;i++){
            m[t[i]]++;
        }
        while(r<n){
            m[s[r]]--;
            if(m[s[r]]>=0) total--;
            while(!total && l<=r){
                if(r-l+1<size) {
                    size=r-l+1;
                    index=l;
                }
                m[s[l]]++;
                if(m[s[l]] >0) total++;
                l++;

            }
            r++;
        }
        if(index==-1) return "";

        string ans=s.substr(index,size);
        
        return ans;
    }
};