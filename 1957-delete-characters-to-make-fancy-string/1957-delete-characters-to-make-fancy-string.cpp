class Solution {
public:
    string makeFancyString(string s) {
        
        int n=s.size();
        int count=1;
        char prev=s[0];
        string ans="";
        ans+=s[0];
        for(int i=1;i<n;i++){
            if(count==2 && prev!=s[i]){
                count=1;
                
            }
            else if(count==2 && prev==s[i]){
                continue;
            }
            else if(prev==s[i]){
                count++;
            }
            
            ans+=s[i];
            prev=s[i];
            

        }
        return ans;
    }
};