class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<int>st;
        int n=colors.size();
        int t=0;
        for(int i=0;i<n;i++){
            bool flag=0;
            if(!st.empty()&&colors[i]==colors[st.top()]){
                if(neededTime[i]<neededTime[st.top()]){
                    flag=1;
                    st.push(i);                  
                }
                t+=neededTime[st.top()];
                st.pop();
                
            }
            if(!flag) st.push(i);
         
        }
        return t;
    }
};