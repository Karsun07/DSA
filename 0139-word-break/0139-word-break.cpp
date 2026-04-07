class Solution {
public:
    int ns,nd;
    unordered_set<string>st;
    bool wordBreak(string s, vector<string>& wordDict) {
        ns=s.size(),nd=wordDict.size();
        for(int i=0;i<nd;i++){
            st.insert(wordDict[i]);
        }
        vector<int>dp(ns+1,0);
        dp[ns]=1;
        for(int i=ns-1;i>=0;i--){
           for(int idx=i;idx<ns;idx++){
                string x=s.substr(i,idx-i+1);
                if(st.count(x)){
                    if(dp[idx+1]) dp[i]=true;
                }
            }
           
        }
        return dp[0];
    }
};