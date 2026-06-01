class Solution {
public:
    int n;
    bool isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int fun(int i,string &s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                mini=min(mini,1+fun(j+1,s,dp));
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s){
        n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
               if(isPalindrome(i,j,s)){
                    mini=min(mini,1+dp[j+1]);
                }
        }
            dp[i]=mini;
        }
          
        return dp[0]-1;
        
       
    }
};