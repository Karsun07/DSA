class Solution {
public:
    int fun(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int idx=i;idx<=j;idx++){
            int burst=nums[idx]*nums[i-1]*nums[j+1]+fun(i,idx-1,nums,dp)+fun(idx+1,j,nums,dp);
            maxi=max(maxi,burst);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(1,n,nums,dp);
    }
};