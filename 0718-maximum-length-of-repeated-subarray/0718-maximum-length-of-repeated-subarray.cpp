class Solution {
public:
    int n1,n2;
    int ans=0;
    int fun(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i>=n1 || j>=n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int curr=0;
        if(nums1[i]==nums2[j]){
            curr=1+fun(i+1,j+1,nums1,nums2,dp);
            ans=max(ans,curr);
        }
        fun(i+1,j,nums1,nums2,dp);
        fun(i,j+1,nums1,nums2,dp);
        return dp[i][j]=curr;

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        fun(0,0,nums1,nums2,dp);
        return ans;
    }
};