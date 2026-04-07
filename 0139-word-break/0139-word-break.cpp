class Solution {
public:
    int ns,nd;
    unordered_set<string>st;
    bool fun(int i,string s,vector<int>&dp){
        if(i>=ns) return true;
        if(dp[i]!=-1) return dp[i];
        for(int idx=i;idx<ns;idx++){
            string x=s.substr(i,idx-i+1);
            if(st.count(x)){
              if(fun(idx+1,s,dp)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        ns=s.size(),nd=wordDict.size();
        for(int i=0;i<nd;i++){
            st.insert(wordDict[i]);
        }
        vector<int>dp(ns,-1);
        return fun(0,s,dp);

    }
};