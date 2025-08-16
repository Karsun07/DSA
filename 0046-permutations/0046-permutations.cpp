class Solution {
public:
    // void perm(vector<int>nums,int n,vector<int>visited,vector<int>temp,vector<vector<int>>&ans){
    //     if(temp.size()==n){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(visited[i]==0){
    //             visited[i]=1;
    //             temp.push_back(arr[i]);
    //             perm(,n,visited,temp,ans);
    //             visited[i]=0;
    //         }
    //     }
    // }
    
    vector<vector<int>> ans;
    void perm(vector<int>& nums, int index){
        if(index == nums.size()-1){
            ans.push_back(nums);
        }
        for(int i = index; i< nums.size(); i++){
            swap(nums[i], nums[index]);
            perm(nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>>ans;
        // vector<int>visited(n,0);
        // vector<int>temp;
        // perm(nums,n,visited,temp,ans);
        perm(nums, 0);
        return ans;
    }
};