class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ']') {
                string temp = "";
                while(st.top() != '['){
                    temp += st.top();
                    st.pop();
                }
                
                st.pop();
                string digit = "";
                while(!st.empty() && isdigit(st.top())){
                    digit += st.top();
                    st.pop();
                }
                reverse(digit.begin(), digit.end());
                int k = stoi(digit);
            
                string ktimes = "";
                while(k--){
                    ktimes += temp;
                }
                
                for(int j = ktimes.size() - 1; j >= 0; j--){
                    st.push(ktimes[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};