class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        string odd;
        string ans="";
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                if(arr[i]%2) odd=(i+'a');
                int x=arr[i]/2;
                while(x--){
                    ans+=(i+'a');
                }
            }
        }
        string rev=ans;
        reverse(rev.begin(),rev.end());
        if(odd.size()) return ans+odd+rev;
        return ans+rev;
        
    
        
    }
};