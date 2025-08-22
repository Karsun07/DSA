class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";
        stack<char> st;
        
        for (int i=0;i<num.size();i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        
        while (!ans.empty() && ans[0] == '0') {
            ans.erase(0, 1);
        }
        if(ans=="") return "0";
        return ans;
    }
};
