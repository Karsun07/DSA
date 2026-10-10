class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        stack<char>st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    if(i+1<n && s[i+1]==')'){
                        i++;
                        ans++;
                    }
                    else{
                        ans+=2;
                    }
                }
                else{
                    if(i+1<n && s[i+1]==')'){
                        i++;
                    }
                    else{
                        ans++;          
                    }
                    st.pop();
                }
            }
        }
        return ans+st.size()*2;
    }
};