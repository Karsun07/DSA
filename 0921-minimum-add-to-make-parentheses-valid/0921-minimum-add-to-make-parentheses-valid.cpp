class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n){
           if(s[i]=='('){
             st.push('(');
           }
           else{
            if(st.empty()){
                ans++;
            }
            else{
                st.pop();
            }
           }
           i++;

        }
        return ans+st.size();
    }
};