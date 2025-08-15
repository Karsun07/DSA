class Solution {
public:
    void subs(vector<int>nums,int i,int n,vector<vector<int>>&ans,vector<int>temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        subs(nums,i+1,n,ans,temp);
        temp.push_back(nums[i]);
        subs(nums,i+1,n,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n=nums.size();
        subs(nums,0,n,ans,temp);
        return ans;


        
    }
};