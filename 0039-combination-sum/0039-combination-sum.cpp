class Solution {
public:
    void sum(vector<int>candidates,int index,int n,int target,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index==n || target<0){
            return;
        }
        
        sum(candidates,index+1,n,target,temp,ans);
        temp.push_back(candidates[index]);
        sum(candidates,index,n,target-candidates[index],temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n=candidates.size();
        sum(candidates,0,n,target,temp,ans);
        return ans;
    }
};